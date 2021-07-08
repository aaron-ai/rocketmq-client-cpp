#include "RpcClientImpl.h"

#include <chrono>

#include "ClientConfig.h"
#include "TlsHelper.h"
#include "absl/time/time.h"

using ClientContext = grpc::ClientContext;

ROCKETMQ_NAMESPACE_BEGIN

void RpcClientImpl::asyncQueryRoute(const QueryRouteRequest& request,
                                    InvocationContext<QueryRouteResponse>* invocation_context) {
  invocation_context->response_reader_ =
      stub_->PrepareAsyncQueryRoute(&invocation_context->context_, request, completion_queue_.get());
  invocation_context->response_reader_->StartCall();
  invocation_context->response_reader_->Finish(&invocation_context->response_, &invocation_context->status_,
                                               invocation_context);
}

void RpcClientImpl::asyncSend(const SendMessageRequest& request,
                              InvocationContext<SendMessageResponse>* invocation_context) {
  invocation_context->response_reader_ =
      stub_->PrepareAsyncSendMessage(&invocation_context->context_, request, completion_queue_.get());
  invocation_context->response_reader_->StartCall();
  invocation_context->response_reader_->Finish(&invocation_context->response_, &invocation_context->status_,
                                               invocation_context);
}

void RpcClientImpl::asyncQueryAssignment(const QueryAssignmentRequest& request,
                                         InvocationContext<QueryAssignmentResponse>* invocation_context) {
  invocation_context->response_reader_ =
      stub_->PrepareAsyncQueryAssignment(&invocation_context->context_, request, completion_queue_.get());
  invocation_context->response_reader_->StartCall();
  invocation_context->response_reader_->Finish(&invocation_context->response_, &invocation_context->status_,
                                               invocation_context);
}

std::shared_ptr<grpc::CompletionQueue>& rocketmq::RpcClientImpl::completionQueue() { return completion_queue_; }

void RpcClientImpl::asyncReceive(const ReceiveMessageRequest& request,
                                 InvocationContext<ReceiveMessageResponse>* invocation_context) {
  invocation_context->response_reader_ =
      stub_->PrepareAsyncReceiveMessage(&invocation_context->context_, request, completion_queue_.get());
  invocation_context->response_reader_->StartCall();
  invocation_context->response_reader_->Finish(&invocation_context->response_, &invocation_context->status_,
                                               invocation_context);
}

void RpcClientImpl::asyncAck(const AckMessageRequest& request,
                             InvocationContext<AckMessageResponse>* invocation_context) {
  assert(invocation_context);
  invocation_context->response_reader_ =
      stub_->PrepareAsyncAckMessage(&invocation_context->context_, request, completion_queue_.get());
  invocation_context->response_reader_->StartCall();
  invocation_context->response_reader_->Finish(&invocation_context->response_, &invocation_context->status_,
                                               invocation_context);
}

void RpcClientImpl::asyncNack(const NackMessageRequest& request,
                              InvocationContext<NackMessageResponse>* invocation_context) {
  assert(invocation_context);
  invocation_context->response_reader_ =
      stub_->PrepareAsyncNackMessage(&invocation_context->context_, request, completion_queue_.get());
  invocation_context->response_reader_->StartCall();
  invocation_context->response_reader_->Finish(&invocation_context->response_, &invocation_context->status_,
                                               invocation_context);
}

void RpcClientImpl::asyncHeartbeat(const HeartbeatRequest& request,
                                   InvocationContext<HeartbeatResponse>* invocation_context) {
  assert(invocation_context);
  invocation_context->response_reader_ =
      stub_->PrepareAsyncHeartbeat(&invocation_context->context_, request, completion_queue_.get());
  invocation_context->response_reader_->StartCall();
  invocation_context->response_reader_->Finish(&invocation_context->response_, &invocation_context->status_,
                                               invocation_context);
}

void RpcClientImpl::asyncHealthCheck(const HealthCheckRequest& request,
                                     InvocationContext<HealthCheckResponse>* invocation_context) {
  assert(invocation_context);
  invocation_context->response_reader_ =
      stub_->PrepareAsyncHealthCheck(&invocation_context->context_, request, completion_queue_.get());
  invocation_context->response_reader_->StartCall();
  invocation_context->response_reader_->Finish(&invocation_context->response_, &invocation_context->status_,
                                               invocation_context);
}

void RpcClientImpl::asyncEndTransaction(const EndTransactionRequest& request,
                                        InvocationContext<EndTransactionResponse>* invocation_context) {
  assert(invocation_context);
  invocation_context->response_reader_ =
      stub_->PrepareAsyncEndTransaction(&invocation_context->context_, request, completion_queue_.get());
  invocation_context->response_reader_->StartCall();
  invocation_context->response_reader_->Finish(&invocation_context->response_, &invocation_context->status_,
                                               invocation_context);
}

bool RpcClientImpl::ok() const {
  return channel_ && grpc_connectivity_state::GRPC_CHANNEL_SHUTDOWN != channel_->GetState(false);
}

void RpcClientImpl::addMetadata(grpc::ClientContext& context,
                                const absl::flat_hash_map<std::string, std::string>& metadata) {
  for (const auto& entry : metadata) {
    context.AddMetadata(entry.first, entry.second);
  }
}

bool RpcClientImpl::needHeartbeat() { return need_heartbeat_; }

void RpcClientImpl::asyncMultiplexingCall(const MultiplexingRequest& request,
                                          InvocationContext<MultiplexingResponse>* invocation_context) {
  assert(invocation_context);
  invocation_context->response_reader_ =
      stub_->PrepareAsyncMultiplexingCall(&invocation_context->context_, request, completion_queue_.get());
  invocation_context->response_reader_->StartCall();
  invocation_context->response_reader_->Finish(&invocation_context->response_, &invocation_context->status_,
                                               invocation_context);
}

void RpcClientImpl::asyncQueryOffset(const QueryOffsetRequest& request,
                                     InvocationContext<QueryOffsetResponse>* invocation_context) {
  assert(invocation_context);
  invocation_context->response_reader_ =
      stub_->PrepareAsyncQueryOffset(&invocation_context->context_, request, completion_queue_.get());
  invocation_context->response_reader_->StartCall();
  invocation_context->response_reader_->Finish(&invocation_context->response_, &invocation_context->status_,
                                               invocation_context);
}

void RpcClientImpl::asyncPull(const PullMessageRequest& request,
                              InvocationContext<PullMessageResponse>* invocation_context) {
  invocation_context->response_reader_ =
      stub_->PrepareAsyncPullMessage(&invocation_context->context_, request, completion_queue_.get());
  invocation_context->response_reader_->StartCall();
  invocation_context->response_reader_->Finish(&invocation_context->response_, &invocation_context->status_,
                                               invocation_context);
}

ROCKETMQ_NAMESPACE_END