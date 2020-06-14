#include "process/launch_params.h"

namespace qui::process {

static LaunchParams launchParams;

void InitLaunchParams(int argc, char* argv[]) {
  launchParams.path = argv[0];
  launchParams.args.reserve(argc - 1);
  for (size_t i = 1; i < argc; i++) {
    launchParams.args.push_back(argv[i]);
  }
}

const LaunchParams& CurrentLaunchParams() {
  return launchParams;
}

}  // namespace qui::process
