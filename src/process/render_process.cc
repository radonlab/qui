#include "render_process.h"

#include "GLFW/glfw3.h"

namespace qui::process {

RenderProcess::RenderProcess() {
  glfwInit();
}

RenderProcess::~RenderProcess() {
  glfwTerminate();
}

int RenderProcess::Execute() {
  return 0;
}

}  // namespace qui::process
