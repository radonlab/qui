#include "process/zygote_process.h"

#include <cstdlib>

namespace qui::process {

ZygoteProcess::ZygoteProcess() {}

ZygoteProcess::~ZygoteProcess() {}

int ZygoteProcess::Execute() {
  return Process::kExitSuccess;
}

void ZygoteProcess::Kill(int exit_code) {
  exit(exit_code);
}

}  // namespace qui::process
