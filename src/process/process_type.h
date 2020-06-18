#ifndef QUI_SRC_PROCESS_PROCESS_TYPE_H_
#define QUI_SRC_PROCESS_PROCESS_TYPE_H_

namespace qui::process {

enum class ProcessType {
  kProcessMaster = 0,
  kProcessZygote,
  kProcessRenderer,
};

const char* GetProcessTypeFlag(ProcessType type);

}  // namespace qui::process

#endif  // QUI_SRC_PROCESS_PROCESS_TYPE_H_
