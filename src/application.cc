#include "application.h"

#include <cstdlib>

#include "gflags/gflags.h"
#include "base/debug.h"
#include "base/process_utils.h"
#include "process/launch_params.h"
#include "process/process_factory.h"
#include "process/process_type.h"

DEFINE_string(type, "", "process type");

namespace qui {

Application::Application(int argc, char* argv[])
    : process_(nullptr) {
  process::InitLaunchParams(argc, argv);
  gflags::SetUsageMessage("");
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  // initialize application
  process_ = process::ProcessFactory::CreateProcess(FLAGS_type);
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
  std::string path = process::CurrentLaunchParams().path;
  std::vector<std::string> args = {
    "--type", GetProcessTypeFlag(process::ProcessType::kProcessRenderer),
  };
  base::LaunchProcess(path, args);
}

}  // namespace qui
