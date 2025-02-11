#pragma GCC optimize("O3")
// #include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

char in[2000002];
char out[7000000];
auto bo = out + 7;
auto eo = out + 8;
int table[1000000];

int readString(char*& out) {
  static auto it = in;
  while (*it < 32) ++it;
  out = it;
  while (*it >= 32) ++it;
  return it - out;
}

void writeSize(int x) {
  *bo-- = '\n';
  if (x == 0) {
    *bo-- = '0';
  } else {
    while (x) *bo-- = '0' + x % 10, x /= 10;
  }
  ++bo;
}

void writeIndex(int x) {
  int n = 0;
  char s[8];
  while (x) s[n++] = '0' + x % 10, x /= 10;
  while (n--) *eo++ = s[n];
  *eo++ = ' ';
}

int main() {
  fread(in, 1, sizeof(in), stdin);
  char *t, *p;
  int nt = readString(t), np = readString(p);

  int idx = 0;
  for (int i = 1; i < np; i++) {
    while (idx && p[i] != p[idx]) idx = table[idx - 1];
    if (p[i] == p[idx]) table[i] = ++idx;
  }

  int cnt = 0;
  idx = 0;
  for (int i = 0; i < nt; i++) {
    while (idx && t[i] != p[idx]) idx = table[idx - 1];
    if (t[i] == p[idx]) {
      if (++idx == np) {
        ++cnt;
        writeIndex(i - np + 2);
        idx = table[idx - 1];
      }
    }
  }
  writeSize(cnt);

  fwrite(bo, 1, eo - bo, stdout);

  return 0;
}
