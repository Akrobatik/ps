// Title : 점호
// Link  : https://www.acmicpc.net/problem/31747
// Time  : 8 ms
// Memory: 2680 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int h1[100000], h2[100000];
  auto hit1 = h1, he1 = h1;
  auto hit2 = h2, he2 = h2;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == '1') {
      *he1++ = i;
    } else {
      *he2++ = i;
    }
  }

  int out = 0;
  int cnt = 0;
  while (out != n) {
    int o = 0;
    if (hit1 != he1 && *hit1 - out < k) ++hit1, ++o;
    if (hit2 != he2 && *hit2 - out < k) ++hit2, ++o;
    out += o;
    ++cnt;
  }
  cout << cnt;

  return 0;
}
