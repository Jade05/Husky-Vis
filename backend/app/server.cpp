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
  }

  void get_attributes(std::vector<Attribute> & _return) {
    // Your implementation goes here
    printf("get_attributes\n");
  }

  void init_run(std::vector<std::string> & _return) {
    // Your implementation goes here
    printf("init_run\n");
    std::vector<husky::visualization::SuggestionObject> topk_suggestions;

    husky::run_job(std::bind(&husky::visualization::Controller::init_visualization, topk_suggestions));
  }

  void ping() {
    std::cout << "hhhhhhhhh" << std::endl;
    printf("Hello world");
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
