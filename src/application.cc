#include "application.h"

#include <cstdlib>

#include "gflags/gflags.h"
#include "base/debug.h"
#include "process/main_process.h"
#include "process/render_process.h"
#include "process/process_utils.h"

const char* program_name;

DEFINE_string(type, "main", "process type");

namespace qui {

Application::Application(int argc, char* argv[])
    : process_(nullptr) {
  program_name = argv[0];
  gflags::SetUsageMessage("");
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  // initialize application
  if (FLAGS_type == "main") {
    process_ = std::make_unique<process::MainProcess>();
  } else if (FLAGS_type == "render") {
    process_ = std::make_unique<process::RenderProcess>();
  } else {
    base::unreachable();
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

void Application::CreateWindow(const char* title, int width, int height) {
  std::vector<std::string> args = {program_name, "--type", "render"};
  process::LaunchProcess(args);
}

}  // namespace qui
