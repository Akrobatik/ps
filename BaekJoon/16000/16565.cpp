// Title : N포커
// Link  : https://www.acmicpc.net/problem/16565
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 10007;

int64_t Comb(int n, int r) {
  int64_t v = 1;
  if (n - r < r) r = n - r;
  for (int i = 0; i < r; i++) {
    v *= n - i;
    v /= (i + 1);
  }
  return v;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int64_t ans = 0;
  for (int i = 4; i <= n; i += 4) {
    int64_t v = Comb(13, i >> 2) * Comb(52 - i, n - i);
    if ((i >> 2) & 1) {
      ans += v;
    } else {
      ans -= v;
    }
  }

  cout << abs(ans) % kMod;

  return 0;
}
