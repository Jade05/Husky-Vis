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

Server::Suggestion& set_suggestion(husky::visualization::SuggestionObject suggestion) {
  Server:::Suggestion s;

  s.measure = suggestion.key.measure;
  s.dimension = suggestion.key.dimension;
  s.chart_type = suggestion.key.chart_type;
  s.aggregate_type = suggestion.key.aggregate_type;
  s.statistical_method = suggestion.key.statistical_method;
  s.aggregate_data.insert(suggestion.aggregate_data.begin(), suggestion.aggregate_data.end());
  s.score = suggestion.score;

  return s;
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

    husky::run_job(std::bind(&husky::visualization::Controller::init_visualization, std::ref(topk_suggestions)));
    
    for (auto topk_suggestion : topk_suggestions) {
        _return.push_back(set_suggestion(topk_suggestion));
    }
  }

  void select_attribute(std::vector<Suggestion> & _return, const std::string& selectAttribute) {
    // Your implementation goes here
    printf("select_attribute\n");

    std::vector<husky::visualization::SuggestionObject> topk_suggestions;

    husky::visualization::Controller::init_visualization(topk_suggestions, selectAttribute);
    
    std::cout << "size:     " + std::to_string(topk_suggestions.size());

    for (auto topk_suggestion : topk_suggestions) {
        _return.push_back(set_suggestion(topk_suggestion));
    }
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
      "constant"
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
