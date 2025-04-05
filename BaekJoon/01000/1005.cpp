// Title : ACM Craft
// Link  : https://www.acmicpc.net/problem/1005
// Time  : 12 ms
// Memory: 2436 KB

#pragma GCC optimize("O3")
// #include <bits/stdc++.h>
#include <stdio.h>

#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
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

int cost[1001];
short memo[1001];
bool visited[1001];
vector<int> cond[1001];

void Solve() {
  int n = readInt(), k = readInt();
  for (int i = 1; i <= n; i++) cost[i] = readInt();
  for (int i = 0; i < k; i++) {
    int x = readInt(), y = readInt();
    ++memo[y];
    cond[x].push_back(y);
  }
  int w = readInt();
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 1; i <= n; i++) {
    if (memo[i] == 0) pq.push({cost[i], i});
  }

  while (!pq.empty()) {
    auto [sec, id] = pq.top();
    pq.pop();

    if (id == w) {
      writeInt(sec, '\n');
      memset(memo + 1, 0, n * 4);
      memset(visited + 1, 0, n);
      for (int i = 1; i <= n; i++) cond[i].clear();
      return;
    }

    if (visited[id]) continue;
    visited[id] = true;

    for (int cid : cond[id]) {
      if (--memo[cid] == 0) pq.push({sec + cost[cid], cid});
    }
  }
}

int main() {
  int t = readInt();
  while (t--) Solve();
  return 0;
}
