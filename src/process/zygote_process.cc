#include "process/zygote_process.h"

#include <cstdlib>

#include "result_codes.h"

namespace qui::process {

ZygoteProcess::ZygoteProcess() {}

ZygoteProcess::~ZygoteProcess() {}

int ZygoteProcess::Execute() {
  return kProcessAbort;
}

void ZygoteProcess::Kill(int exit_code) {
  exit(exit_code);
}

}  // namespace qui::process
