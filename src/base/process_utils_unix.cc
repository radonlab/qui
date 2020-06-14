#include "base/process_utils.h"

#include <unistd.h>

#include "base/debug.h"

namespace qui::base {

int LaunchProcess(const std::string& path, const std::vector<std::string>& args) {
  int pid = fork();
  if (pid == -1) {
    base::panic("fork process failed");
  } else if (pid == 0) {
    std::vector<char*> argv;
    argv.reserve(args.size() + 2);
    argv.push_back(const_cast<char*>(path.c_str()));
    for (const std::string& arg : args) {
      argv.push_back(const_cast<char*>(arg.c_str()));
    }
    argv.push_back(nullptr);
    execv(path.c_str(), argv.data());
    base::panic("process error");
  }
  return pid;
}

}  // namespace qui::base
