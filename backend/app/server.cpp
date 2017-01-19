#include "./gen-cpp/Something.h"
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

using namespace  ::App;

class SomethingHandler : virtual public SomethingIf {
 public:
  SomethingHandler() {
    // Your initialization goes here
  }

   int32_t ping() {
     std::vector<husky::visualization::SuggestionObject> topk_suggestions;

     husky::run_job(std::bind(&husky::visualization::Controller::init_visualization, topk_suggestions));
     return 66666;
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
  boost::shared_ptr<SomethingHandler> handler(new SomethingHandler());
  boost::shared_ptr<TProcessor> processor(new SomethingProcessor(handler));
  boost::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  boost::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  boost::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
