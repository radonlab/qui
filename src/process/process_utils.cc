#include "process_utils.h"

#include <unistd.h>

namespace qui::process {

int LaunchProcess(const std::vector<std::string>& args) {
  int code = fork();
  if (code == -1) {
  } else if (code == 0) {
    const char* exe = args[0].c_str();
    std::vector<char*> argv;
    for (const std::string& arg : args) {
      argv.push_back(const_cast<char*>(arg.c_str()));
    }
    argv.push_back(nullptr);
    execv(exe, argv.data());
  }
}

}  // namespace qui::process
