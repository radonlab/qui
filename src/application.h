#ifndef QUI_SRC_APPLICATION_H_
#define QUI_SRC_APPLICATION_H_

namespace qui {

class Application {
 public:
  Application(int argc, const char* argv[]);
  ~Application();
  int Run();
};

}  // namespace qui

#endif  // QUI_SRC_APPLICATION_H_
