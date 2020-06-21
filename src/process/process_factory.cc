#include "process/process_factory.h"

#include "base/debug.h"
#include "process/process_type.h"
#include "process/master_process.h"
#include "process/zygote_process.h"
#include "process/renderer_process.h"

namespace qui::process {

std::unique_ptr<Process> ProcessFactory::CreateProcess(const std::string& type) {
  if (type == GetProcessTypeFlag(process::ProcessType::kProcessMaster)) {
    return std::make_unique<process::MasterProcess>();
  } else if (type == GetProcessTypeFlag(process::ProcessType::kProcessZygote)) {
    return std::make_unique<process::ZygoteProcess>();
  } else if (type == GetProcessTypeFlag(process::ProcessType::kProcessRenderer)) {
    return std::make_unique<process::RendererProcess>();
  } else {
    base::panic("invalid type argument");
  }
}

}  // namespace qui::process
