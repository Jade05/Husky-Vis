#include "./gen-cpp/App.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

#include <vector>

#include "husky/core/engine.hpp"
#include "core/common/base_obj.hpp"

#include "controller.hpp"


using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::Server;

void set_suggestions(std::vector<Server::Suggestion>& d_suggestions, std::vector<husky::visualization::SuggestionObject> s_suggestions) {

    for (auto suggestion : s_suggestions) {
        Server::Suggestion s;

        s.measure = suggestion.key.measure;
        s.dimension = suggestion.key.dimension;
        s.chart_type = suggestion.key.chart_type;
        s.aggregate_type = suggestion.key.aggregate_type;
        s.statistical_method = suggestion.key.statistical_method;
        s.aggregate_data.insert(suggestion.aggregate_data.begin(), suggestion.aggregate_data.end());
        s.score = suggestion.score;

        d_suggestions.push_back(s);
    }
}

class AppHandler : virtual public AppIf {
 public:
  AppHandler() {
    // Your initialization goes here
  }

  void get_suggestions(std::vector<Suggestion> & _return) {
    // Your implementation goes here
    printf("get_suggestions\n");

    std::vector<husky::visualization::SuggestionObject> topk_suggestions;

    husky::run_job(std::bind(&husky::visualization::Controller::init_visualization, std::ref(topk_suggestions), ""));

    set_suggestions(_return, topk_suggestions);
  }

  void select_attribute(std::vector<Suggestion> & _return, const std::string& selectAttribute) {
    // Your implementation goes here
    printf("select_attribute------\n");

    std::cout << "selectAttributes:  " << selectAttribute << std::endl;

    std::vector<husky::visualization::SuggestionObject> topk_suggestions;

    std::cout << "running job!" << std::endl;
    husky::run_job(std::bind(&husky::visualization::Controller::init_visualization, std::ref(topk_suggestions), selectAttribute));


    std::cout << "size:     " + std::to_string(topk_suggestions.size()) << std::endl;
    set_suggestions(_return, topk_suggestions);

  }

  void get_attributes(std::vector<Attribute> & _return) {
    // Your implementation goes here
    printf("get_attributes\n");

    std::vector<std::string> attributes;
    husky::visualization::Controller::get_attributes(attributes);

    for (auto attribute : attributes) {
      Server::Attribute attr;
      attr.name = attribute;
      _return.push_back(attr);
    }

  }

};

int main(int argc, char **argv) {
  // init args

  std::vector<std::string> args({
      "data",
      "data_schema",
      "distribute",
      "topk",
      "constant",
      "mongo_server",
      "mongo_db",
      "mongo_collection"
  });

  husky::visualization::Controller::init_with_args(argc, argv, args);

  int port = 9090;
  boost::shared_ptr<AppHandler> handler(new AppHandler());
  boost::shared_ptr<TProcessor> processor(new AppProcessor(handler));
  boost::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  boost::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  boost::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
