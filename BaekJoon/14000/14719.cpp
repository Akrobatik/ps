// Title : 빗물
// Link  : https://www.acmicpc.net/problem/14719
// Time  : 0 ms
// Memory: 1684 KB

#pragma GCC optimize("O3")
// #include <bits/stdc++.h>
#include <stdio.h>
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

using us = unsigned int;

us hs[500];
us ans = 0;

void ToRight(us*& b, us*& e) {
  us hh = *b;
  while (b < e) {
    if (hh < *b) return;
    ans += hh - *(b++);
  }
  ++b;
}

void ToLeft(us*& b, us*& e) {
  us hh = *e;
  while (b < e) {
    if (hh < *e) return;
    ans += hh - *(e--);
  }
  --e;
}

int main() {
  us h = readInt();
  us w = readInt();
  auto b = hs;
  auto e = hs;
  while (w--) *(e++) = readInt();
  --e;

  while (b < e) {
    if (*b < *e) {
      ToRight(b, e);
    } else {
      ToLeft(b, e);
    }
  }

  writeInt(ans, '\n');

  return 0;
}
