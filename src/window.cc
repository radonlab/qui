#include "window.h"

#include "GLFW/glfw3.h"

namespace qui {

Window::Window(const char* title, int width, int height) {
  hwnd_ = glfwCreateWindow(width, height, title, nullptr, nullptr);
  glfwMakeContextCurrent(reinterpret_cast<GLFWwindow*>(hwnd_));
}

Window::~Window() {
  glfwDestroyWindow(reinterpret_cast<GLFWwindow*>(hwnd_));
}

}  // namespace qui
