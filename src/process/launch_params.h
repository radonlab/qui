#ifndef QUI_SRC_PROCESS_LAUNCH_PARAMS_H_
#define QUI_SRC_PROCESS_LAUNCH_PARAMS_H_

#include <string>
#include <vector>

namespace qui::process {

struct LaunchParams {
  std::string path;
  std::vector<std::string> args;
};

void InitLaunchParams(int argc, char* argv[]);
const LaunchParams& CurrentLaunchParams();

}  // namespace qui::process

#endif  // QUI_SRC_PROCESS_LAUNCH_PARAMS_H_
