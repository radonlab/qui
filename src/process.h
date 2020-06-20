#ifndef QUI_SRC_PROCESS_H_
#define QUI_SRC_PROCESS_H_

#include "qui_types.h"

namespace qui {

class Process {
 public:
  enum ExitCode {
    kExitContinue = -1,
    kExitSuccess  = 0,
    kExitFailure  = 1,
  };

  Process() = default;
  virtual ~Process() = default;
  virtual int Execute() = 0;
  virtual void Exit(int exit_code) = 0;

 private:
  DISALLOW_COPY_AND_ASSIGN(Process);
};

}  // namespace qui

#endif  // QUI_SRC_PROCESS_H_
