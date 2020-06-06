#ifndef QUI_SRC_BASE_DEBUG_H_
#define QUI_SRC_BASE_DEBUG_H_

#include <cassert>
#include <cstdlib>
#include <iostream>

namespace qui::base {

inline void println() {
  // empty
}

template<typename T>
void println(const T& arg) {
  std::cout << arg << std::endl;
}

template<typename T, typename... Args>
void println(const T& arg, const Args&... args) {
  std::cout << arg;
  println(args...);
}

template<typename... Args>
void debug(const Args&... args) {
#ifndef NDEBUG
  println(args...);
#endif
}

template<typename... Args>
void panic(const Args&... args) {
  debug(args...);
  // safely exit in subprocess
  _Exit(EXIT_FAILURE);
}

}  // namespace qui::base

#endif  // QUI_SRC_BASE_DEBUG_H_
