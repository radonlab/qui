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
void println(T&& arg) {
  std::cout << arg << std::endl;
}

template<typename T, typename... Args>
void println(T&& arg, Args&&... args) {
  constexpr size_t args_count = 1 + sizeof...(Args);
  static_assert(args_count <= 6, "too many arguments");
  std::cout << arg << " ";
  println(args...);
}

template<typename... Args>
void debug(Args&&... args) {
#ifndef NDEBUG
  println(args...);
#endif
}

template<typename... Args>
void panic(Args&&... args) {
  debug(args...);
  // safely exit in subprocess
  _Exit(EXIT_FAILURE);
}

}  // namespace qui::base

#endif  // QUI_SRC_BASE_DEBUG_H_
