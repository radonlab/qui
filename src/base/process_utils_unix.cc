#include "base/process_utils.h"

#include <unistd.h>

#include "base/debug.h"

namespace qui::base {

int LaunchProcess(const std::vector<std::string>& args) {
  int pid = fork();
  if (pid == -1) {
    base::panicf("fork process failed");
  } else if (pid == 0) {
    const char* exe = args[0].c_str();
    std::vector<char*> argv;
    for (const std::string& arg : args) {
      argv.push_back(const_cast<char*>(arg.c_str()));
    }
    argv.push_back(nullptr);
    execv(exe, argv.data());
    base::unreachable();
  }
  return pid;
}

}  // namespace qui::base
