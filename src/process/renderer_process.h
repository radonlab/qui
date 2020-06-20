#ifndef QUI_SRC_PROCESS_RENDERER_PROCESS_H_
#define QUI_SRC_PROCESS_RENDERER_PROCESS_H_

#include "qui_types.h"
#include "process.h"

namespace qui::process {

class RendererProcess : public Process {
 public:
  RendererProcess();
  ~RendererProcess();
  int Execute();
  void Exit(int exit_code);

 private:
  DISALLOW_COPY_AND_ASSIGN(RendererProcess);
};

}  // namespace qui::process

#endif  // QUI_SRC_PROCESS_RENDERER_PROCESS_H_
