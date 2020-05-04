#ifndef QUI_SRC_PROCESS_RENDER_PROCESS_H_
#define QUI_SRC_PROCESS_RENDER_PROCESS_H_

#include "qui_types.h"
#include "process/process.h"

namespace qui {

class RenderProcess : public Process {
 public:
  RenderProcess();
  ~RenderProcess();
  int Execute();

 private:
  DISALLOW_COPY_AND_ASSIGN(RenderProcess);
};

}  // namespace qui

#endif  // QUI_SRC_PROCESS_RENDER_PROCESS_H_
