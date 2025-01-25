#pragma GCC optimize("O3")
// #include <bits/stdc++.h>
#include <stdio.h>
#include <time.h>
using namespace std;

inline int readChar();
template <class T = int>
inline T readInt();
template <class T>
inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeWord(const char* s);
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
inline void writeWord(const char* s) {
  while (*s) writeChar(*s++);
}
struct Flusher {
  ~Flusher() {
    if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
  }
} flusher;

using ull = unsigned long long;

constexpr ull prime = 1e9 + 9;
const ull base = []() {
  ull v = ((ull)time(nullptr) * 1664525 + 1013904223) % prime;
  return v ? v : 1;
}();

ull forwards[2001];
ull backwards[2001];
ull polyhashes[2001] = {1};

int main() {
  int n = readInt();
  for (int i = 0; i < n; i++) {
    ull v = readInt();
    forwards[i + 1] = (forwards[i] + v * polyhashes[i]) % prime;
    backwards[i + 1] = (base * backwards[i] + v) % prime;
    polyhashes[i + 1] = (polyhashes[i] * base) % prime;
  }

  n = readInt();
  while (n--) {
    int x = readInt(), y = readInt();
    bool ok = (forwards[y] + polyhashes[y] * backwards[x - 1]) % prime ==
              (forwards[x - 1] + polyhashes[x - 1] * backwards[y]) % prime;
    writeChar('0' + ok);
    writeChar('\n');
  }

  return 0;
}
