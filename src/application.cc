#include "application.h"

#include "gflags/gflags.h"
#include "render_process.h"

DEFINE_string(type, "main", "process type");

namespace qui {

Application::Application(int argc, char* argv[]) {
  gflags::SetUsageMessage("");
  gflags::ParseCommandLineFlags(&argc, &argv, true);
}

Application::~Application() {
  gflags::ShutDownCommandLineFlags();
}

int Application::SpawnProcess() {
  return 1;
}

int Application::Run() {
  return 0;
}

}  // namespace qui
