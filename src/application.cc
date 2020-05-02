#include "application.h"

#include "GLFW/glfw3.h"

namespace qui {

Application::Application(int argc, const char* argv[]) {
  glfwInit();
}

Application::~Application() {
  glfwTerminate();
}

int Application::Run() {
  return 0;
}

}  // namespace qui
