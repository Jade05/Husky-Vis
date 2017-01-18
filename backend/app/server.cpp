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

using boost::shared_ptr;

using namespace  ::App;

class SomethingHandler : virtual public SomethingIf {
 public:
  SomethingHandler() {
    // Your initialization goes here
  }

  int32_t ping() {
    // Your implementation goes here
    printf("ping, server-side api is called\n");
  }

  void run_job() {
    std::vector<husky::visualization::SuggestionObject> topk_suggestions;

    husky::run_job(husky::visualization::Controller::init_visualization(topk_suggestions));
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
  husky::visualization::Controller::init_with_args();

  int port = 9090;
  shared_ptr<SomethingHandler> handler(new SomethingHandler());
  shared_ptr<TProcessor> processor(new SomethingProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
