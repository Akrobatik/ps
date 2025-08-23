// Title : Game with Segment Tree
// Link  : https://www.acmicpc.net/problem/34158 
// Time  : 160 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k, g;
  cin >> k >> g;

  int64_t nmax = 1LL << (k - 1);

  auto Grundy = [&](int x) {
    return x & -x;
  };

  auto Check = [&](int64_t l, int64_t r) {
    int x = 0;

    l += nmax - 1, r += nmax;
    for (int i = 1; l < r; l >>= 1, r >>= 1, i++) {
      if (l & 1) x ^= Grundy(i), ++l;
      if (r & 1) x ^= Grundy(i), --r;
    }
    return x == 0;
  };

  while (g--) {
    int64_t l, r;
    cin >> l >> r;
    cout << (Check(l, r) ? "mj1000j\n" : "swlee0202\n");
  }

  return 0;
}