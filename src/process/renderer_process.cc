#include "process/renderer_process.h"

#include <cstdlib>

#include "GLFW/glfw3.h"

namespace qui::process {

RendererProcess::RendererProcess() {
  glfwInit();
}

RendererProcess::~RendererProcess() {
  glfwTerminate();
}

int RendererProcess::Execute() {
  return 0;
}

void RendererProcess::Kill(int exit_code) {
  // exit subprocess
  _Exit(exit_code);
}

}  // namespace qui::process
