// Title : A+를 향하여
// Link  : https://www.acmicpc.net/problem/34806 
// Time  : 164 ms
// Memory: 2164 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, t, w;
  cin >> n >> t >> w;

  vector<pair<int, int>> arr(n);
  for (auto& [a, b] : arr) cin >> a >> b;
  sort(arr.begin(), arr.end());

  vector<int64_t> memo, mnxt;

  auto Build = [&](int64_t x) {
    memo.assign(t + 1, 0);
    mnxt.resize(t + 1);
    for (auto [a, b] : arr) {
      copy(memo.begin(), memo.end(), mnxt.begin());
      int64_t v = max<int64_t>(a - x, 0);
      for (int64_t i = x; i + v <= t; i++) {
        mnxt[i + v] = max<int64_t>(mnxt[i + v], memo[i] + b);
      }
      for (int64_t i = x + 1; i <= t; i++) {
        mnxt[i] = max<int64_t>(mnxt[i], mnxt[i - 1]);
      }
      swap(memo, mnxt);
    }
  };

  auto Calc = [&](int64_t x) {
    Build(x);
    return memo[t];
  };

  int64_t lo = -1, hi = t + 1;
  while (lo + 1 < hi) {
    int64_t mid = (lo + hi) >> 1;
    if (Calc(mid) < w) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  cout << (hi <= t ? hi : -1);

  return 0;
}