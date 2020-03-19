#include "GLFW/glfw3.h"

int main(int argc, const char* argv[]) {
  GLFWwindow* window;
  glfwInit();
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }
  glfwTerminate();
  return 0;
}
