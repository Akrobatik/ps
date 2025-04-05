// Title : 색칠된 공들
// Link  : https://www.acmicpc.net/problem/1250 
// Time  : 156 ms
// Memory: 118620 KB

#pragma GCC optimize("O3")
// #include <bits/stdc++.h>
#include <stdio.h>

#include <algorithm>

using namespace std;

inline int getChar();
inline int readChar();
inline void readString(char* out);
template <class T = int>
inline T readInt();
template <class T>
inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeString(const char* s);
constexpr int kInBufSize = 1 << 18;
constexpr int kOutBufSize = 1 << 8;

constexpr int kMax = 10000001;

int memo[kMax + 1];
int lens[kMax];
int heap[kMax];
auto hit = heap;

bool Compare(int l, int r) {
  return lens[l] != lens[r] ? lens[l] < lens[r] : l > r;
}

void Push(int idx) {
  *hit++ = idx;
  push_heap(heap, hit, Compare);
}

int Pop() {
  int top = heap[0];
  pop_heap(heap, hit, Compare);
  --hit;
  return top;
}

int main() {
  int n = readInt(), k = readInt();
  char last = readChar();
  int len = 1, idx;
  for (int i = 2; i <= n; i++) {
    char c = readChar();
    if (last != c) {
      idx = i - len;
      memo[i - 1] = idx << 7;
      memo[idx] = ((i - 1) << 7) | last;
      lens[idx] = len;
      if (len != 1) Push(idx);
      last = c;
      len = 1;
    } else {
      ++len;
    }
  }
  idx = n - len + 1;
  memo[n] = idx << 7;
  memo[idx] = (n << 7) | last;
  lens[idx] = len;
  if (len != 1) Push(idx);

  int ans = 0;
  bool found = false;
  while (hit != heap) {
    int top = Pop();
    if (!(memo[top] & 0x7F)) continue;
    ++ans;
    int ridx = memo[top] >> 7;
    int l = min<int>(top, ridx);
    int r = memo[l] >> 7;
    if (l <= k && k <= r) {
      found = true;
      break;
    }

    int lr = l - 1;
    int ll = memo[lr] >> 7;
    int lm, ls;
    char lc;
    if ((memo[ll] >> 7) < ll) {
      lm = ll;
      ls = lens[lm];
      lc = memo[lm] & 0x7F;
      ll = memo[lm] >> 7;
    } else {
      lm = 0;
      ls = lens[ll];
      lc = memo[ll] & 0x7F;
    }

    int rl = r + 1;
    int rr = memo[rl] >> 7;
    int rm, rs;
    char rc;
    if (rr != kMax && rl != (memo[rr] >> 7)) {
      rm = memo[rr] >> 7;
      rs = lens[rm];
      rc = memo[rm] & 0x7F;
    } else {
      rm = 0;
      rs = lens[rl];
      rc = memo[rl] & 0x7F;
    }

    if (ll && lr && rl && rr && lc && lc == rc) {
      memo[lm ? lm : ll] ^= lc;
      memo[rm ? rm : rl] ^= rc;
      memo[ll] = rr << 7;
      memo[rr] = top << 7;
      memo[top] = (ll << 7) | lc;
      lens[top] = ls + rs;
      Push(top);
    } else {
      memo[top] = memo[l] = 0;
      if (ll) memo[ll] = (r << 7) | lc;
      memo[r] = (lm ? lm : ll) << 7;
    }
  }

  if (!found) {
    for (int i = 1; i <= k; i++) {
      if (memo[i] & 0x7F) ++ans;
    }
  }
  writeInt(ans);

  return 0;
}

// FastIO
// https://github.com/justiceHui/AlgorithmImplement/blob/master/misc/FastInput.cpp
inline int getChar() {
  static char buf[kInBufSize];
  static int len = 0, pos = 0;
  if (pos == len) pos = 0, len = fread(buf, 1, kInBufSize, stdin);
  if (pos == len) return -1;
  return buf[pos++];
}
inline int readChar() {
  int c = getChar();
  while (c <= 32) c = getChar();
  return c;
}
inline void readString(char* out) {
  int c = getChar();
  while (c <= 32) c = getChar();
  do {
    *(out++) = c;
    c = getChar();
  } while (c > 32);
  *out = 0;
}
template <class T>
inline T readInt() {
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-') s = -1, c = getChar();
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}
static int write_pos = 0;
static char write_buf[kOutBufSize];
inline void writeChar(int x) {
  if (write_pos == kOutBufSize)
    fwrite(write_buf, 1, kOutBufSize, stdout), write_pos = 0;
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
inline void writeString(const char* s) {
  while (*s) writeChar(*s++);
}
struct Flusher {
  ~Flusher() {
    if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
  }
} flusher;
