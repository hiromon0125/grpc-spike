#pragma once

#include <grpcpp/grpcpp.h>

#include <google/protobuf/empty.pb.h>

#include <iosfwd>
#include <ostream>
#include <string>

#include "icd.grpc.pb.h"

namespace talos::icd::server {

class TalosOperatorService final : public ::talos::icd::v1::TalosOperator::Service {
public:
    explicit TalosOperatorService(std::ostream& log_stream);

    ::grpc::Status Handshake(::grpc::ServerContext* context,
                             const ::talos::icd::v1::HandshakeRequest* request,
                             ::talos::icd::v1::HandshakeResponse* response) override;

    ::grpc::Status PolarPanDiscrete(::grpc::ServerContext* context,
                                    const ::talos::icd::v1::PolarPanDiscreteRequest* request,
                                    ::talos::icd::v1::CommandResult* response) override;

    ::grpc::Status Home(::grpc::ServerContext* context,
                        const ::talos::icd::v1::HomeRequest* request,
                        ::talos::icd::v1::CommandResult* response) override;

    ::grpc::Status PolarPanContinuousStart(::grpc::ServerContext* context,
                                           const ::talos::icd::v1::PolarPanContinuousStartRequest* request,
                                           ::talos::icd::v1::CommandResult* response) override;

    ::grpc::Status PolarPanContinuousStop(::grpc::ServerContext* context,
                                          const ::google::protobuf::Empty* request,
                                          ::talos::icd::v1::CommandResult* response) override;

    ::grpc::Status CartesianMoveDiscrete(::grpc::ServerContext* context,
                                         const ::talos::icd::v1::CartesianMoveDiscreteRequest* request,
                                         ::talos::icd::v1::CommandResult* response) override;

    ::grpc::Status CartesianMoveContinuousStart(::grpc::ServerContext* context,
                                                const ::talos::icd::v1::CartesianMoveContinuousStartRequest* request,
                                                ::talos::icd::v1::CommandResult* response) override;

    ::grpc::Status CartesianMoveContinuousStop(::grpc::ServerContext* context,
                                               const ::google::protobuf::Empty* request,
                                               ::talos::icd::v1::CommandResult* response) override;

    ::grpc::Status ExecuteHardwareOperation(::grpc::ServerContext* context,
                                            const ::talos::icd::v1::ExecuteHardwareOperationRequest* request,
                                            ::talos::icd::v1::ExecuteHardwareOperationResponse* response) override;

    ::grpc::Status GetSpeed(::grpc::ServerContext* context,
                            const ::google::protobuf::Empty* request,
                            ::talos::icd::v1::GetSpeedResponse* response) override;

    ::grpc::Status SetSpeed(::grpc::ServerContext* context,
                            const ::talos::icd::v1::SetSpeedRequest* request,
                            ::talos::icd::v1::CommandResult* response) override;

    ::grpc::Status SavePosition(::grpc::ServerContext* context,
                                const ::talos::icd::v1::SavePositionRequest* request,
                                ::talos::icd::v1::CommandResult* response) override;

    ::grpc::Status DeletePosition(::grpc::ServerContext* context,
                                  const ::talos::icd::v1::DeletePositionRequest* request,
                                  ::talos::icd::v1::CommandResult* response) override;

    ::grpc::Status GoToPosition(::grpc::ServerContext* context,
                                const ::talos::icd::v1::GoToPositionRequest* request,
                                ::talos::icd::v1::CommandResult* response) override;

    ::grpc::Status SetPolarPosition(::grpc::ServerContext* context,
                                    const ::talos::icd::v1::SetPolarPositionRequest* request,
                                    ::talos::icd::v1::CommandResult* response) override;

    ::grpc::Status GetPolarPosition(::grpc::ServerContext* context,
                                    const ::talos::icd::v1::GetPolarPositionRequest* request,
                                    ::talos::icd::v1::GetPolarPositionResponse* response) override;

    ::grpc::Status SetCartesianPosition(::grpc::ServerContext* context,
                                        const ::talos::icd::v1::SetCartesianPositionRequest* request,
                                        ::talos::icd::v1::CommandResult* response) override;

    ::grpc::Status GetCartesianPosition(::grpc::ServerContext* context,
                                        const ::talos::icd::v1::GetCartesianPositionRequest* request,
                                        ::talos::icd::v1::GetCartesianPositionResponse* response) override;

private:
    void LogRequest(const std::string& method_name) const;

    template <typename Request>
    void LogRequest(const std::string& method_name, const Request& request) const;

    static void PopulateSuccess(::talos::icd::v1::CommandResult* response);

    std::ostream& log_;
};

}  // namespace talos::icd::server

template <typename Request>
inline void talos::icd::server::TalosOperatorService::LogRequest(const std::string& method_name,
                                                                 const Request& request) const {
    const std::string summary = request.ShortDebugString();
    if (summary.empty()) {
        log_ << "[" << method_name << "]" << std::endl;
    } else {
        log_ << "[" << method_name << "] " << summary << std::endl;
    }
}
