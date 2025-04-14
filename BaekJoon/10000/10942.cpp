// Title : 팰린드롬?
// Link  : https://www.acmicpc.net/problem/10942 
// Time  : 20 ms
// Memory: 1740 KB

// Title : 팰린드롬？
// Link  : https://www.acmicpc.net/problem/10942
// Time  : 16 ms
// Memory: 1740 KB

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
constexpr ull base = 3167;

int nums[2001];
ull forwards[2001];
ull backwards[2001];
ull polyhashes[2001] = {1};

int main() {
  int n = readInt();
  register ull* fptr = forwards;
  register ull* bptr = backwards;
  register ull* pptr = polyhashes;
  while (n--) {
    ull v = readInt();
    *(++fptr) = (*fptr + v * *pptr) % prime;
    *(++bptr) = (base * *bptr + v) % prime;
    *(++pptr) = (*pptr * base) % prime;
  }

  n = readInt();
  while (n--) {
    int x = readInt() - 1, y = readInt();
    bool ok = (forwards[y] + polyhashes[y] * backwards[x]) % prime ==
              (forwards[x] + polyhashes[x] * backwards[y]) % prime;
    writeChar('0' + ok);
    writeChar('\n');
  }

  return 0;
}
