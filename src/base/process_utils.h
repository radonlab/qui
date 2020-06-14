#ifndef QUI_SRC_BASE_PROCESS_UTILS_H_
#define QUI_SRC_BASE_PROCESS_UTILS_H_

#include <string>
#include <vector>

namespace qui::base {

int LaunchProcess(const std::string& path, const std::vector<std::string>& args);

}  // namespace qui::base

#endif  // QUI_SRC_BASE_PROCESS_UTILS_H_
