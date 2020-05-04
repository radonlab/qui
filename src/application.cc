#include "application.h"

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
    process_ = std::make_unique<MainProcess>();
  } else if (FLAGS_type == "render") {
    process_ = std::make_unique<RenderProcess>();
  }
}

Application::~Application() {
  gflags::ShutDownCommandLineFlags();
}

int Application::ExecuteProcess() {
  return process_->Execute();
}

int Application::Run() {
  return 0;
}

}  // namespace qui
