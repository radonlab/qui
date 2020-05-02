#include "application.h"

#include "render_process.h"

namespace qui {

Application::Application(int argc, const char* argv[]) {
}

Application::~Application() {
}

int Application::SpawnProcess() {
  return 1;
}

int Application::Run() {
  return 0;
}

}  // namespace qui
