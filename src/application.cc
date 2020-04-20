#include "application.h"

#include "GLFW/glfw3.h"

namespace qui {

Application::Application() {
  glfwInit();
}

Application::~Application() {
  glfwTerminate();
}

void Application::Run() {}

}  // namespace qui
