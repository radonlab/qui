#include "window.h"

#include "GLFW/glfw3.h"

namespace qui {

Window::Window(int width, int height) {
  hwnd_ = glfwCreateWindow(width, height, "", nullptr, nullptr);
}

Window::~Window() {
  glfwDestroyWindow(hwnd_);
}

}  // namespace qui
