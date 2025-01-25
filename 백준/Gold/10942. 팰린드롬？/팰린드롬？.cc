#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

inline int readChar();
template <class T = int>
inline T readInt();
template <class T>
inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeWord(const char *s);
static const int buf_size = 1 << 18;
inline int getChar() {
#ifndef LOCAL
  static char buf[buf_size];
  static int len = 0, pos = 0;
  if (pos == len) pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len) return -1;
  return buf[pos++];
#endif
}
inline int readChar() {
#ifndef LOCAL
  int c = getChar();
  while (c <= 32) c = getChar();
  return c;
#else
  char c;
  cin >> c;
  return c;
#endif
}
template <class T>
inline T readInt() {
#ifndef LOCAL
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-') s = -1, c = getChar();
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
#else
  T x;
  cin >> x;
  return x;
#endif
}
static int write_pos = 0;
static char write_buf[buf_size];
inline void writeChar(int x) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = x;
}
template <class T>
inline void writeInt(T x, char end) {
  if (x < 0) writeChar('-'), x = -x;
  char s[24];
  int n = 0;
  while (x || !n) s[n++] = '0' + x % 10, x /= 10;
  while (n--) writeChar(s[n]);
  if (end) writeChar(end);
}
inline void writeWord(const char *s) {
  while (*s) writeChar(*s++);
}
struct Flusher {
  ~Flusher() {
    if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
  }
} flusher;

constexpr uint64_t prime = 1e9 + 9;
uint64_t base = []() {
  mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<uint64_t> dist(1, prime - 1);
  return dist(gen);
}();

uint64_t forwards[2001];
uint64_t backwards[2001];
uint64_t polyhashes[2001];

int main() {
  int n = readInt();
  fill_n(polyhashes, n + 1, 1);
  for (int i = 0; i < n; i++) {
    uint64_t v = readInt();
    forwards[i + 1] = (forwards[i] + v * polyhashes[i]) % prime;
    backwards[i + 1] = (base * backwards[i] + v) % prime;
    polyhashes[i + 1] = (polyhashes[i] * base) % prime;
  }

  int m = readInt();
  while (m--) {
    int x = readInt(), y = readInt();
    if ((forwards[y] + (polyhashes[y] * backwards[x - 1]) % prime) % prime ==
        (forwards[x - 1] + (polyhashes[x - 1] * backwards[y]) % prime) % prime) {
      writeChar('1');
    } else {
      writeChar('0');
    }
    writeChar('\n');
  }

  return 0;
}
