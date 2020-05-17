#include "process/master_process.h"

#include <cstdlib>

#include "result_codes.h"

namespace qui::process {

MasterProcess::MasterProcess() {}

MasterProcess::~MasterProcess() {}

int MasterProcess::Execute() {
  return kProcessAbort;
}

void MasterProcess::Kill(int exit_code) {
  exit(exit_code);
}

}  // namespace qui::process
