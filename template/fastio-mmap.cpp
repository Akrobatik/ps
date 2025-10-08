#include <memory.h>
#include <sys/stat.h>
#include <unistd.h>

#include <concepts>
#include <cstdint>
#include <string>

using namespace std;

#if defined(__GNUC__)
#define LIKELY(x) (__builtin_expect(!!(x), 1))
#define UNLIKELY(x) (__builtin_expect(!!(x), 0))
#else
#define LIKELY(x) (x)
#define UNLIKELY(x) (x)
#endif

struct FastIO {
  FastIO() : ob(obuf), oe(obuf + OB) {
    struct stat st;
    fstat(0, &st);
    ib = (uint8_t*)syscall(9, 0, st.st_size, 1, 2, 0, 0);
    ie = ib + st.st_size;
  }
  ~FastIO() { Flush(); }

  explicit operator bool() const { return ib < ie; }

  FastIO& operator>>(char& out) {
    uint8_t *p = ib, *e = ie;
    if (UNLIKELY(p >= e)) return *this;

    uint8_t v = *p++;
    while (UNLIKELY(v <= 32)) v = *p++;

    if (LIKELY(p != e)) {
      if (*p <= 32) ++p;
    }

    ib = p;
    out = (char)v;
    return *this;
  }

  FastIO& operator>>(string& out) {
    uint8_t *p = ib, *b = ib, *e = ie;
    if (UNLIKELY(p >= e)) return *this;

    while (LIKELY(*p > 32)) ++p;

    int len = p - b;
    out.resize(len);
    memcpy(out.data(), b, len);

    ib = p + 1;
    return *this;
  }

  template <typename T>
    requires is_integral_v<T> && is_unsigned_v<T>
  FastIO& operator>>(T& out) {
    T v = 0;
    uint8_t *p = ib, *e = ie;
    if (UNLIKELY(p >= e)) return *this;

    uint32_t d = *p++ - 48;
    do {
      v = v * 10 + d;
      d = *p++ - 48;
    } while (LIKELY(d <= 9u));

    ib = p;
    out = v;
    return *this;
  }

  template <typename T>
    requires is_integral_v<T> && is_signed_v<T>
  FastIO& operator>>(T& out) {
    T v = 0;
    uint8_t *p = ib, *e = ie;
    if (UNLIKELY(p >= e)) return *this;

    bool neg = false;
    if (*p == 45) neg = true, ++p;

    uint32_t d = *p++ - 48;
    if (neg) {
      do {
        v = v * 10 - d;
        d = *p++ - 48;
      } while (LIKELY(d <= 9u));
    } else {
      do {
        v = v * 10 + d;
        d = *p++ - 48;
      } while (LIKELY(d <= 9u));
    }

    ib = p;
    out = v;
    return *this;
  }

  FastIO& operator<<(char v) {
    if (UNLIKELY(ob == oe)) Flush();
    *ob++ = (uint8_t)v;
    return *this;
  }

  FastIO& operator<<(const string& v) {
    int n = v.size();
    const char* p = v.c_str();

    while (LIKELY(n > 0)) {
      int rem = oe - ob;
      if (UNLIKELY(rem <= 0)) {
        Flush();
        rem = oe - ob;
      }

      int cut = (rem < n ? rem : n);
      memcpy(ob, p, cut);

      n -= cut, p += cut, ob += cut;
    }
    return *this;
  }

  template <typename T>
    requires is_integral_v<T> && is_unsigned_v<T>
  FastIO& operator<<(T v) {
    int n = 0;
    uint8_t buf[32];
    while (LIKELY(v > 0 || !n)) buf[n++] = v % 10 + 48, v /= 10;

    if (UNLIKELY(oe - ob < n)) Flush();
    uint8_t* p = ob;
    while (n--) *p++ = buf[n];
    ob = p;
    return *this;
  }

  template <typename T>
    requires is_integral_v<T> && is_signed_v<T>
  FastIO& operator<<(T v) {
    if (v < 0) {
      if (UNLIKELY(ob == oe)) Flush();
      *ob++ = '-';
      v = -v;
    }

    int n = 0;
    uint8_t buf[32];
    while (LIKELY(v > 0 || !n)) buf[n++] = v % 10 + 48, v /= 10;

    if (UNLIKELY(oe - ob < n)) Flush();
    uint8_t* p = ob;
    while (n--) *p++ = buf[n];
    ob = p;
    return *this;
  }

 private:
  void Flush() {
    int len = ob - obuf;
    if (LIKELY(len > 0)) {
      write(1, obuf, len);
      ob = obuf;
    }
  }

  static constexpr int OB = 1 << 18;

  uint8_t obuf[OB];
  uint8_t *ib, *ie, *ob, *oe;
} io;