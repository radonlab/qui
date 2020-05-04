#ifndef QUI_SRC_PROCESS_MAIN_PROCESS_H_
#define QUI_SRC_PROCESS_MAIN_PROCESS_H_

#include "qui_types.h"
#include "process.h"

namespace qui::process {

class MainProcess : public Process {
 public:
  MainProcess();
  ~MainProcess();
  int Execute();

 private:
  DISALLOW_COPY_AND_ASSIGN(MainProcess);
};

}  // namespace qui::process

#endif  // QUI_SRC_PROCESS_MAIN_PROCESS_H_
