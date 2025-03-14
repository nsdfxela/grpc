#include "grpc_dynamic.h"

#include <grpcpp/grpcpp.h>

#include "helper.h"

void grpc_dynamic::createChannelSsl() {
  const std::string target_str = "localhost:50051";

  constexpr char kRootCertificate[] = "credentials/root.crt";
  grpc::SslCredentialsOptions ssl_options;
  ssl_options.pem_root_certs = LoadStringFromFile(kRootCertificate);

  grpc::ChannelArguments args;

  auto chan = grpc::CreateCustomChannel(
      target_str, grpc::SslCredentials(ssl_options), args);
  std::chrono::milliseconds timeout{1500};
  try {
    if (!chan->WaitForConnected(
            gpr_time_add(gpr_now(GPR_CLOCK_MONOTONIC),
                         gpr_time_from_millis(timeout.count(), GPR_TIMESPAN))))
      throw std::runtime_error("Failed to connect to " + target_str);
  } catch (std::exception& ex) {
    std::cout << "Something really bad happened" << ex.what() << std::endl;
    return;
  }
  std::cout << "The custom channel was created successfully, but sometimes the "
               "process hangs at the exit moment."
               "It only happens when the channel creation logic is moved to a dll. \n"
         "--------------------------------------------------------------------\n"
         "--------------------------------------------------------------------\n"
         "--------------------------------------------------------------------\n"
         "--------------------------------------------------------------------\n"
         "--------------------------------------------------------------------\n";
}
