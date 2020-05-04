#ifndef QUI_SRC_PROCESS_H_
#define QUI_SRC_PROCESS_H_

#include "qui_types.h"

namespace qui {

class Process {
 public:
  Process() = default;
  virtual ~Process() = default;
  virtual int Execute() = 0;

 private:
  DISALLOW_COPY_AND_ASSIGN(Process);
};

}  // namespace qui

#endif  // QUI_SRC_PROCESS_H_
