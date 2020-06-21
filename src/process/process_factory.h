#ifndef QUI_SRC_PROCESS_PROCESS_FACTORY_H_
#define QUI_SRC_PROCESS_PROCESS_FACTORY_H_

#include <memory>
#include <string>

#include "qui_types.h"
#include "process.h"

namespace qui::process {

class ProcessFactory {
 public:
  static std::unique_ptr<Process> CreateProcess(const std::string& type);

 private:
  DISALLOW_IMPLICIT_CONSTRUCTORS(ProcessFactory);
};

}  // namespace qui::process

#endif  // QUI_SRC_PROCESS_PROCESS_FACTORY_H_
