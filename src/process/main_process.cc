#include "main_process.h"

#include "result_codes.h"

namespace qui::process {

MainProcess::MainProcess() {}

MainProcess::~MainProcess() {}

int MainProcess::Execute() {
  return kProcessAbort;
}

}  // namespace qui::process
