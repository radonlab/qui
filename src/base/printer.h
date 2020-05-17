#ifndef QUI_SRC_BASE_PRINTER_H_
#define QUI_SRC_BASE_PRINTER_H_

#include <memory>

namespace qui::base {

template<typename Ch, typename Alloc = std::allocator<Ch>>
class GenericPrinter {
 public:
  explicit GenericPrinter(const Ch* fmt)
    : fmt_(fmt) {
  }

  template<typename T, typename... Args>
  void apply(const T& arg, const Args&... args) {
    constexpr size_t args_count = 1 + sizeof...(Args);
    static_assert(args_count <= 6, "too many arguments");
    apply(args...);
  }

  void apply() {}

 private:
  const Ch* fmt_;
};

using Printer = GenericPrinter<char>;

}  // namespace qui::base

#endif  // QUI_SRC_BASE_PRINTER_H_
