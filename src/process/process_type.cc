#include "process/process_type.h"

#include <type_traits>

namespace qui::process {

static const char* kProcessTypeFlags[] = {
  "",
  "zygote",
  "renderer",
};

const char* GetProcessTypeFlag(ProcessType type) {
  using U = std::underlying_type<ProcessType>::type;
  return kProcessTypeFlags[static_cast<U>(type)];
}

}  // namespace qui::process
