#include "process/master_process.h"

#include <cstdlib>

#include "base/process_utils.h"
#include "process/launch_params.h"
#include "process/process_type.h"

namespace qui::process {

MasterProcess::MasterProcess() {}

MasterProcess::~MasterProcess() {}

int MasterProcess::Execute() {
  std::string path = CurrentLaunchParams().path;
  std::vector<std::string> args = {"--type", "zygote"};
  base::LaunchProcess(path, args);
  return Process::kExitContinue;
}

void MasterProcess::Kill(int exit_code) {
  exit(exit_code);
}

}  // namespace qui::process
