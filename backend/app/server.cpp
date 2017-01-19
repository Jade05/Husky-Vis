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
        Server::Suggestion s;
        s.measure = topk_suggestion.key.measure;
        s.dimension = topk_suggestion.key.dimension;
        s.chart_type = topk_suggestion.key.chart_type;
        s.aggregate_type = topk_suggestion.key.aggregate_type;
        s.statistical_method = topk_suggestion.key.statistical_method;
        s.aggregate_data.insert(topk_suggestion.aggregate_data.begin(), topk_suggestion.aggregate_data.end());
        s.score = topk_suggestion.score;
        
        _return.push_back(s);
    }
  }

  void get_attributes(std::vector<Attribute> & _return) {
    // Your implementation goes here
    printf("get_attributes\n");
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
