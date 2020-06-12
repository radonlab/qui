#include "application.h"

#include <cstdlib>

#include "gflags/gflags.h"
#include "base/debug.h"
#include "base/process_utils.h"
#include "process/launch_params.h"
#include "process/master_process.h"
#include "process/renderer_process.h"

enum ProcessType {
  kProcessMaster = 0,
  kProcessRenderer,
};

const char* kProcessTypeFlags[] = {
  "",
  "renderer"
};

DEFINE_string(type, kProcessTypeFlags[kProcessMaster], "process type");

namespace qui {

Application::Application(int argc, char* argv[])
    : process_(nullptr) {
  process::SetLaunchParams(argc, argv);
  gflags::SetUsageMessage("");
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  // initialize application
  if (FLAGS_type == kProcessTypeFlags[kProcessMaster]) {
    process_ = std::make_unique<process::MasterProcess>();
  } else if (FLAGS_type == kProcessTypeFlags[kProcessRenderer]) {
    process_ = std::make_unique<process::RendererProcess>();
  } else {
    base::panic("invalid type argument");
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
  std::string path = process::CurrentLaunchParams().path;
  std::vector<std::string> args = {path, "--type", kProcessTypeFlags[kProcessRenderer]};
  base::LaunchProcess(args);
}

}  // namespace qui
