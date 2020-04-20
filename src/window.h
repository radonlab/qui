#ifndef QUI_SRC_WINDOW_H_
#define QUI_SRC_WINDOW_H_

namespace qui {

class Window {
 public:
  Window(int width, int height);
  ~Window();

 private:
  void* hwnd_;
};

}  // namespace qui

#endif  // QUI_SRC_WINDOW_H_
