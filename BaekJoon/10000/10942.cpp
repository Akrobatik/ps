// Title : 팰린드롬?
// Link  : https://www.acmicpc.net/problem/10942 
// Time  : 12 ms
// Memory: 13168 KB

#pragma GCC optimize("O3")
#include <immintrin.h>
#include <malloc.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

#define R(x)                        \
  x = 0;                            \
  if (*in == '0') return 0;         \
  ii = 0;                           \
  do x = x * 10 + *in - '0';        \
  while (*++in >= '0' && ++ii < 7); \
  ++in;

int s[200001];

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);

  struct stat st;
  fstat(0, &st);
  char* in = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
  int ii;

  int R(n2);
  int n = (n2 << 1) + 1;
  for (int i = 1; i < n; i += 2) {
    R(s[i]);
  }

  int table[200001];
  table[0] = table[n - 1] = 0;

  int p, r = 0;
  for (int i = 1; i < n - 1; i++) {
    if (i > r) {
      p = r = i;
      while (r < n && r <= (p << 1) && s[r] == s[(p << 1) - r]) ++r;
      table[i] = --r - p;
    } else {
      if (table[(p << 1) - i] < r - i) {
        table[i] = table[(p << 1) - i];
      } else if (table[(p << 1) - i] > r - i) {
        table[i] = r - i;
      } else {
        p = i;
        while (r < n && r <= (p << 1) && s[r] == s[(p << 1) - r]) ++r;
        table[i] = --r - p;
      }
    }
  }

  int R(q);
  char* out = (char*)malloc(q << 1);
  auto os = out;
  while (q--) {
    int R(l);
    int R(r);
    *out++ = '0' + (table[l + r - 1] >= r - l + 1);
    *out++ = '\n';
  }
  fwrite(os, 1, out - os, stdout);

  return 0;
}
