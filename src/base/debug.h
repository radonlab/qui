#ifndef QUI_SRC_BASE_DEBUG_H_
#define QUI_SRC_BASE_DEBUG_H_

#include <cstdlib>

#include "base/printer.h"

namespace qui::base {

template<typename Ch, typename... Args>
void debugf(const Ch* fmt, const Args&... args) {
#ifndef NDEBUG
  Printer(fmt).apply(args...);
#endif
}

template<typename Ch, typename... Args>
void panicf(const Ch* fmt, const Args&... args) {
  debugf(fmt, args...);
  // safely exit in subprocess
  _Exit(EXIT_FAILURE);
}

inline void unreachable() {
  panicf("unreachable");
}

}  // namespace qui::base

#endif  // QUI_SRC_BASE_DEBUG_H_
