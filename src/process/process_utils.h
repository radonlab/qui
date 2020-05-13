#ifndef QUI_SRC_PROCESS_PROCESS_UTILS_H_
#define QUI_SRC_PROCESS_PROCESS_UTILS_H_

#include <string>
#include <vector>

#include "process.h"

namespace qui::process {

int LaunchProcess(const std::vector<std::string>& args);

}  // namespace qui::process

#endif  // QUI_SRC_PROCESS_PROCESS_UTILS_H_
