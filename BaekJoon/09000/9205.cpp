// Title : 맥주 마시면서 걸어가기
// Link  : https://www.acmicpc.net/problem/9205 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<pair<int16_t, int16_t>> yx;
  vector<int8_t> memo;

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    memo[b] = a;
  };

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    yx.resize(n + 2);
    for (auto& [y, x] : yx) cin >> y >> x;

    memo.resize(n + 2);
    iota(memo.begin(), memo.end(), 0);

    for (int i = 1; i < n + 2; i++) {
      auto [iy, ix] = yx[i];
      for (int j = 0; j < i; j++) {
        auto [jy, jx] = yx[j];
        if (abs(iy - jy) + abs(ix - jx) <= 1000) {
          Union(i, j);
        }
      }
    }

    cout << (Find(0) == Find(n + 1) ? "happy\n" : "sad\n");
  }

  return 0;
}
