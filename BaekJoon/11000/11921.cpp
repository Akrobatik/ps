// Title : 0.1
// Link  : https://www.acmicpc.net/problem/11921 
// Time  : 72 ms
// Memory: 2532 KB

#include <bits/stdc++.h>

using namespace std;

#include <unistd.h>

#if defined(__GNUC__)
#define LIKELY(x) (__builtin_expect(!!(x), 1))
#define UNLIKELY(x) (__builtin_expect(!!(x), 0))
#else
#define LIKELY(x) (x)
#define UNLIKELY(x) (x)
#endif

constexpr int IB = 1 << 18;
constexpr int OB = 1 << 18;

struct FastIO {
  FastIO() : good(true), ib(ibuf), ie(ibuf), ob(obuf), oe(obuf + OB) {}

  explicit operator bool() const { return good; }

  template <typename T>
    requires is_integral_v<T> && is_unsigned_v<T>
  FastIO& operator>>(T& out) {
    T v = 0;
    uint8_t *p = ib, *e = ie;
    if (UNLIKELY(p == e)) {
      if (UNLIKELY(!Refill())) return *this;
      p = ib, e = ie;
    }

    uint32_t d = *p++ - 48;
    do {
      v = v * 10 + d;
      if (UNLIKELY(p == e)) {
        ib = p;
        if (UNLIKELY(!Refill())) return *this;
        p = ib, e = ie;
      }
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
    if (UNLIKELY(p == e)) {
      if (UNLIKELY(!Refill())) return *this;
      p = ib, e = ie;
    }

    bool sign = false;
    if (*p == 45) {
      sign = true;
      if (UNLIKELY(++p == e)) {
        ib = p;
        if (UNLIKELY(!Refill())) return *this;
        p = ib, e = ie;
      }
    }

    uint32_t d = *p++ - 48;
    do {
      v = v * 10 + d;
      if (UNLIKELY(p == e)) {
        ib = p;
        if (UNLIKELY(!Refill())) return *this;
        p = ib, e = ie;
      }
      d = *p++ - 48;
    } while (LIKELY(d <= 9u));
    ib = p;

    out = (sign ? -v : v);
    return *this;
  }

 private:
  bool Refill() {
    int n = read(0, ibuf, IB);
    if (n <= 0) {
      good = false;
      return false;
    }
    ib = ibuf, ie = ibuf + n;
    return true;
  }

  bool good;
  uint8_t ibuf[IB], obuf[OB];
  uint8_t *ib, *ie, *ob, *oe;
} io;

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);

  int n;
  io >> n;

  int64_t sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    io >> x;
    sum += x;
  }

  printf("%d\n%lld", n, sum);

  return 0;
}