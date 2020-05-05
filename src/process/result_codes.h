#ifndef QUI_SRC_PROCESS_RESULT_CODES_H_
#define QUI_SRC_PROCESS_RESULT_CODES_H_

namespace qui::process {

enum ResultCode {
  kProcessAbort  = -1,
  kProcessNormal = 0,
  kProcessError  = 1,
};

}  // namespace qui::process

#endif  // QUI_SRC_PROCESS_RESULT_CODES_H_
