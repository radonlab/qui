#ifndef QUI_SRC_PROCESS_ZYGOTE_PROCESS_H_
#define QUI_SRC_PROCESS_ZYGOTE_PROCESS_H_

#include "qui_types.h"
#include "process.h"

namespace qui::process {

class ZygoteProcess : public Process {
 public:
  ZygoteProcess();
  ~ZygoteProcess();
  int Execute();
  void Kill(int exit_code);

 private:
  DISALLOW_COPY_AND_ASSIGN(ZygoteProcess);
};

}  // namespace qui::process

#endif  // QUI_SRC_PROCESS_ZYGOTE_PROCESS_H_
