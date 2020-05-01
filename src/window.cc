#include "window.h"

#include "GLFW/glfw3.h"

namespace qui {

Window* Window::CreateWindow(const char* title, int width, int height) {
  GLFWwindow* hwnd = glfwCreateWindow(width, height, title, nullptr, nullptr);
  // bind GL context
  glfwMakeContextCurrent(hwnd);
  return new Window(hwnd);
}

Window::Window(void* hwnd)
    : hwnd_(hwnd) {}

Window::~Window() {}

int Window::Run() {
  GLFWwindow* hwnd = reinterpret_cast<GLFWwindow*>(hwnd_);
  while (!glfwWindowShouldClose(hwnd)) {
    glfwSwapBuffers(hwnd);
    glfwPollEvents();
  }
  return 0;
}

void Window::Destroy() {
  glfwDestroyWindow(reinterpret_cast<GLFWwindow*>(hwnd_));
  delete this;
}

}  // namespace qui
