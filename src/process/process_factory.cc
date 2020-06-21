#include "process/process_factory.h"

#include "base/debug.h"
#include "process/process_type.h"
#include "process/master_process.h"
#include "process/zygote_process.h"
#include "process/renderer_process.h"

namespace qui::process {

std::unique_ptr<Process> ProcessFactory::CreateProcess(const std::string& type) {
  if (type == GetProcessTypeFlag(ProcessType::kProcessMaster)) {
    return std::make_unique<MasterProcess>();
  } else if (type == GetProcessTypeFlag(ProcessType::kProcessZygote)) {
    return std::make_unique<ZygoteProcess>();
  } else if (type == GetProcessTypeFlag(ProcessType::kProcessRenderer)) {
    return std::make_unique<RendererProcess>();
  } else {
    base::panic("invalid type argument");
  }
}

}  // namespace qui::process
