#ifndef QUI_SRC_APPLICATION_H_
#define QUI_SRC_APPLICATION_H_

#include "qui_types.h"

namespace qui {

class Application {
 public:
  Application(int argc, const char* argv[]);
  ~Application();
  void CreateWindow(const char* title, int width, int height);
  int Run();

 private:
  DISALLOW_COPY_AND_ASSIGN(Application);
};

}  // namespace qui

#endif  // QUI_SRC_APPLICATION_H_
