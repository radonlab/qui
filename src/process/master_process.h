#ifndef QUI_SRC_PROCESS_MASTER_PROCESS_H_
#define QUI_SRC_PROCESS_MASTER_PROCESS_H_

#include "qui_types.h"
#include "process.h"

namespace qui::process {

class MasterProcess : public Process {
 public:
  MasterProcess();
  ~MasterProcess();
  int Execute();
  void Exit(int exit_code);

 private:
  DISALLOW_COPY_AND_ASSIGN(MasterProcess);
};

}  // namespace qui::process

#endif  // QUI_SRC_PROCESS_MASTER_PROCESS_H_
