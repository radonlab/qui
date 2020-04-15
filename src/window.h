#ifndef QUI_SRC_WINDOW_H_
#define QUI_SRC_WINDOW_H_

struct GLFWwindow;

namespace qui {

class Window {
 public:
  Window(int width, int height);
  ~Window();

 private:
  GLFWwindow* hwnd_;
};

}  // namespace qui

#endif  // QUI_SRC_WINDOW_H_
