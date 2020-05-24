#ifndef QUI_SRC_BASE_PRINTER_H_
#define QUI_SRC_BASE_PRINTER_H_

#include <cstdio>

#include "qui_types.h"

namespace qui::base {

template<typename Ch, typename Alloc = std::allocator<Ch>>
class GenericFormatter {
 public:
  template<typename Char>
  struct BaseBuffer {
    Char* s;
    Char* p;

    BaseBuffer() {
      s = new Char[100];
      p = s;
    }

    ~BaseBuffer() {
      delete[] s;
    }

    void Put(Char c) {
      *(p++) = c;
    }

    const Char* Get() const {
      return s;
    }
  };

  using Buffer = BaseBuffer<Ch>;

  explicit GenericFormatter(const Ch* fmt)
    : buf_(), fmt_(fmt), ps_(fmt) {}

  ~GenericFormatter() {}

  template<typename T>
  void Format(const T& arg) {
    while (*ps_ != '\0' && *ps_ != '{') {
      buf_.Put(*ps_);
      ps_++;
    }
    while (*ps_ != '\0' && *ps_ != '}') {
      ps_++;
    }
    buf_ << arg;
  }

  const Ch* CStr() {
    while (*ps_ != '\0') {
      buf_.Put(*ps_);
      ps_++;
    }
    return buf_.Get();
  }

 private:
  Buffer buf_;
  const Ch* fmt_;
  const Ch* ps_;
};

template<typename Ch, typename Alloc = std::allocator<Ch>>
class GenericFormatPrinter {
 public:
  using Formatter = GenericFormatter<Ch, Alloc>;

  explicit GenericFormatPrinter(const Ch* fmt)
    : formatter_(fmt) {}

  ~GenericFormatPrinter() {}

  template<typename T, typename... Args>
  void Apply(const T& arg, const Args&... args) {
    constexpr size_t args_count = 1 + sizeof...(Args);
    static_assert(args_count <= 6, "too many arguments");
    formatter_.Format(arg);
    Apply(args...);
  }

  void Apply() {
    puts(formatter_.CStr());
  }

 private:
  Formatter formatter_;

  DISALLOW_COPY_AND_ASSIGN(GenericFormatPrinter);
};

using FormatPrinter = GenericFormatPrinter<char>;

}  // namespace qui::base

#endif  // QUI_SRC_BASE_PRINTER_H_
