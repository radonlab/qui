#include "GLFW/glfw3.h"
#include "context.h"

int main(int argc, const char* argv[]) {
  GLFWwindow* window;
  glfwInit();
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  glfwMakeContextCurrent(window);
  qui::InitContext();
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    qui::RescaleContext(640, 480);
    glfwSwapBuffers(window);
  }
  glfwTerminate();
  return 0;
}
