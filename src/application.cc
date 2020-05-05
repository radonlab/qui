#include "application.h"

#include <cstdlib>

#include "gflags/gflags.h"
#include "process/main_process.h"
#include "process/render_process.h"

DEFINE_string(type, "main", "process type");

namespace qui {

Application::Application(int argc, char* argv[])
    : process_(nullptr) {
  gflags::SetUsageMessage("");
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  // initialize application
  if (FLAGS_type == "main") {
    process_ = std::make_unique<process::MainProcess>();
  } else if (FLAGS_type == "render") {
    process_ = std::make_unique<process::RenderProcess>();
  }
}

Application::~Application() {
  gflags::ShutDownCommandLineFlags();
}

int Application::ExecuteProcess() {
  if (process_ == nullptr) {
    exit(-1);
  }
  return process_->Execute();
}

int Application::Run() {
  return 0;
}

}  // namespace qui
