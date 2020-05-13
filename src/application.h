#ifndef QUI_SRC_APPLICATION_H_
#define QUI_SRC_APPLICATION_H_

#include <memory>

#include "qui_types.h"

namespace qui {

class Process;

class Application {
 public:
  Application(int argc, char* argv[]);
  ~Application();
  int ExecuteProcess();
  int Run();
  void CreateWindow(const char* title, int width, int height);
  Process* process() { return process_.get(); }

 private:
  std::unique_ptr<Process> process_;

  DISALLOW_COPY_AND_ASSIGN(Application);
};

}  // namespace qui

#endif  // QUI_SRC_APPLICATION_H_
