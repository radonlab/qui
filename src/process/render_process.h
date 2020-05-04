#ifndef QUI_SRC_PROCESS_RENDER_PROCESS_H_
#define QUI_SRC_PROCESS_RENDER_PROCESS_H_

#include "qui_types.h"
#include "process.h"

namespace qui::process {

class RenderProcess : public Process {
 public:
  RenderProcess();
  ~RenderProcess();
  int Execute();

 private:
  DISALLOW_COPY_AND_ASSIGN(RenderProcess);
};

}  // namespace qui::process

#endif  // QUI_SRC_PROCESS_RENDER_PROCESS_H_
