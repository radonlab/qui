#include "context.h"

#include "GLFW/glfw3.h"
#include "GrContext.h"
#include "gl/GrGLAssembleInterface.h"
#include "SkSurface.h"

namespace qui {

static sk_sp<GrContext> context;

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
  context = GrContext::MakeGL(gl);
  if (context == nullptr) {
    return false;
  }
  return true;
}

bool RescaleContext(int width, int height) {
  GrGLFramebufferInfo buf_info;
  buf_info.fFBOID = 0;
  buf_info.fFormat = GL_RGBA8;
  GrBackendRenderTarget render_target(width, height, 0, 0, buf_info);
  sk_sp<SkSurface> surface = SkSurface::MakeFromBackendRenderTarget(
      context.get(),
      render_target,
      kBottomLeft_GrSurfaceOrigin,
      kRGBA_8888_SkColorType,
      nullptr,
      nullptr
  );
  SkCanvas* canvas = surface->getCanvas();
  SkPaint paint;
  paint.setColor(SK_ColorWHITE);
  canvas->drawPaint(paint);
  context->flush();
}

}  // namespace qui
