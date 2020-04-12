#include "context.h"

#include "GLFW/glfw3.h"
#include "GrContext.h"
#include "gl/GrGLAssembleInterface.h"

namespace qui {

static GrGLFuncPtr get_glfw_proc(void* ctx, const char name[]) {
  return glfwGetProcAddress(name);
}

bool InitContext() {
  sk_sp<const GrGLInterface> gl = GrGLMakeAssembledInterface(
      nullptr,
      get_glfw_proc
  );
  if (gl == nullptr) {
    return false;
  }
  sk_sp<GrContext> context = GrContext::MakeGL(gl);
  if (context == nullptr) {
    return false;
  }
  return true;
}

}  // namespace qui
