#include "process/launch_params.h"

namespace qui::process {

static LaunchParams launchParams;

LaunchParams SetLaunchParams(int argc, char* argv[]) {
  launchParams.args.reserve(argc);
  for (size_t i = 0; i < argc; i++) {
    launchParams.args.push_back(argv[i]);
  }
}

LaunchParams CurrentLaunchParams() {
  return launchParams;
}

}  // namespace qui::process
