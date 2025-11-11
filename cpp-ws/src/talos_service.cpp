#include "talos_service.h"

#include <iostream>

namespace talos::icd::server {

namespace ticd = ::talos::icd::v1;

TalosOperatorService::TalosOperatorService(std::ostream& log_stream) : log_(log_stream) {}

::grpc::Status TalosOperatorService::Handshake(::grpc::ServerContext*,
                                               const ticd::HandshakeRequest* request,
                                               ticd::HandshakeResponse* response) {
    LogRequest("Handshake", *request);
    PopulateSuccess(response->mutable_status());
    response->set_major_version(1);
    response->set_minor_version(0);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::PolarPanDiscrete(::grpc::ServerContext*,
                                                      const ticd::PolarPanDiscreteRequest* request,
                                                      ticd::CommandResult* response) {
    LogRequest("PolarPanDiscrete", *request);
    PopulateSuccess(response);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::Home(::grpc::ServerContext*,
                                          const ticd::HomeRequest* request,
                                          ticd::CommandResult* response) {
    LogRequest("Home", *request);
    PopulateSuccess(response);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::PolarPanContinuousStart(::grpc::ServerContext*,
                                                             const ticd::PolarPanContinuousStartRequest* request,
                                                             ticd::CommandResult* response) {
    LogRequest("PolarPanContinuousStart", *request);
    PopulateSuccess(response);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::PolarPanContinuousStop(::grpc::ServerContext*,
                                                            const ::google::protobuf::Empty* request,
                                                            ticd::CommandResult* response) {
    LogRequest("PolarPanContinuousStop", *request);
    PopulateSuccess(response);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::CartesianMoveDiscrete(::grpc::ServerContext*,
                                                           const ticd::CartesianMoveDiscreteRequest* request,
                                                           ticd::CommandResult* response) {
    LogRequest("CartesianMoveDiscrete", *request);
    PopulateSuccess(response);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::CartesianMoveContinuousStart(::grpc::ServerContext*,
                                                                  const ticd::CartesianMoveContinuousStartRequest* request,
                                                                  ticd::CommandResult* response) {
    LogRequest("CartesianMoveContinuousStart", *request);
    PopulateSuccess(response);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::CartesianMoveContinuousStop(::grpc::ServerContext*,
                                                                 const ::google::protobuf::Empty* request,
                                                                 ticd::CommandResult* response) {
    LogRequest("CartesianMoveContinuousStop", *request);
    PopulateSuccess(response);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::ExecuteHardwareOperation(::grpc::ServerContext*,
                                                               const ticd::ExecuteHardwareOperationRequest* request,
                                                               ticd::ExecuteHardwareOperationResponse* response) {
    LogRequest("ExecuteHardwareOperation", *request);
    PopulateSuccess(response->mutable_status());
    response->set_subcommand_id(0);
    response->clear_payload();
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::GetSpeed(::grpc::ServerContext*,
                                              const ::google::protobuf::Empty* request,
                                              ticd::GetSpeedResponse* response) {
    LogRequest("GetSpeed", *request);
    PopulateSuccess(response->mutable_status());
    response->set_speed(0);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::SetSpeed(::grpc::ServerContext*,
                                              const ticd::SetSpeedRequest* request,
                                              ticd::CommandResult* response) {
    LogRequest("SetSpeed", *request);
    PopulateSuccess(response);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::SavePosition(::grpc::ServerContext*,
                                                  const ticd::SavePositionRequest* request,
                                                  ticd::CommandResult* response) {
    LogRequest("SavePosition", *request);
    PopulateSuccess(response);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::DeletePosition(::grpc::ServerContext*,
                                                    const ticd::DeletePositionRequest* request,
                                                    ticd::CommandResult* response) {
    LogRequest("DeletePosition", *request);
    PopulateSuccess(response);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::GoToPosition(::grpc::ServerContext*,
                                                  const ticd::GoToPositionRequest* request,
                                                  ticd::CommandResult* response) {
    LogRequest("GoToPosition", *request);
    PopulateSuccess(response);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::SetPolarPosition(::grpc::ServerContext*,
                                                      const ticd::SetPolarPositionRequest* request,
                                                      ticd::CommandResult* response) {
    LogRequest("SetPolarPosition", *request);
    PopulateSuccess(response);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::GetPolarPosition(::grpc::ServerContext*,
                                                      const ticd::GetPolarPositionRequest* request,
                                                      ticd::GetPolarPositionResponse* response) {
    LogRequest("GetPolarPosition", *request);
    PopulateSuccess(response->mutable_status());
    response->set_delta_tenths_deg(0);
    response->set_azimuth_tenths_deg(0);
    response->set_radius_tenths(0);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::SetCartesianPosition(::grpc::ServerContext*,
                                                          const ticd::SetCartesianPositionRequest* request,
                                                          ticd::CommandResult* response) {
    LogRequest("SetCartesianPosition", *request);
    PopulateSuccess(response);
    return ::grpc::Status::OK;
}

::grpc::Status TalosOperatorService::GetCartesianPosition(::grpc::ServerContext*,
                                                          const ticd::GetCartesianPositionRequest* request,
                                                          ticd::GetCartesianPositionResponse* response) {
    LogRequest("GetCartesianPosition", *request);
    PopulateSuccess(response->mutable_status());
    response->set_x_tenths_mm(0);
    response->set_y_tenths_mm(0);
    response->set_z_tenths_mm(0);
    return ::grpc::Status::OK;
}

void TalosOperatorService::LogRequest(const std::string& method_name) const {
    log_ << "[" << method_name << "]" << std::endl;
}

void TalosOperatorService::PopulateSuccess(ticd::CommandResult* response) {
    if (response != nullptr) {
        response->set_return_code(0);
    }
}

}  // namespace talos::icd::server
