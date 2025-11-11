#include <grpcpp/grpcpp.h>

#include <iostream>
#include <memory>
#include <string>

#include "talos_service.h"

int main(int argc, char** argv) {
    const std::string listen_address = (argc > 1) ? argv[1] : "0.0.0.0:50051";

    talos::icd::server::TalosOperatorService service(std::cout);

    grpc::ServerBuilder builder;
    builder.AddListeningPort(listen_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server = builder.BuildAndStart();
    if (!server) {
        std::cerr << "Failed to start TalosOperator server on " << listen_address << std::endl;
        return 1;
    }

    std::cout << "TalosOperator server listening on " << listen_address << std::endl;
    server->Wait();

    return 0;
}
