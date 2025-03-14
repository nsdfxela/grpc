#pragma once
#define GRPC_DYNAMIC_EXPORT __declspec(dllexport)


namespace grpc_dynamic {

  void GRPC_DYNAMIC_EXPORT createChannelSsl();

}
