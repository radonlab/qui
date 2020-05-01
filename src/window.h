#ifndef QUI_SRC_WINDOW_H_
#define QUI_SRC_WINDOW_H_

#include "qui_types.h"

namespace qui {

class Window {
 public:
  static Window* CreateWindow(const char* title, int width, int height);
  int Run();
  void Destroy();

 private:
  explicit Window(void* hwnd);
  ~Window();

  void* hwnd_;

  DISALLOW_COPY_AND_ASSIGN(Window);
};

}  // namespace qui

#endif  // QUI_SRC_WINDOW_H_
