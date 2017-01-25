// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "App.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

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

  void select_attribute(std::vector<Suggestion> & _return, const std::string& selectAttribute) {
    // Your implementation goes here
    printf("select_attribute\n");
  }

  void get_attributes(std::vector<Attribute> & _return) {
    // Your implementation goes here
    printf("get_attributes\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<AppHandler> handler(new AppHandler());
  shared_ptr<TProcessor> processor(new AppProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

