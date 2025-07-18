// Title : 레드 블루 스패닝 트리
// Link  : https://www.acmicpc.net/problem/4792 
// Time  : 152 ms
// Memory: 8556 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  vector<pair<int, int>> arr, brr;
  vector<int> memo;

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return false;
    memo[b] = a;
    return true;
  };

  auto Min = [&]() {
    memo.resize(n + 1);
    iota(memo.begin(), memo.end(), 0);

    int r = 0, b = 0;
    for (auto [u, v] : brr) {
      r += Union(u, v);
    }
    for (auto [u, v] : arr) {
      b += Union(u, v);
    }
    return r + b + 1 == n ? b : INT_MAX;
  };

  auto Max = [&]() {
    memo.resize(n + 1);
    iota(memo.begin(), memo.end(), 0);

    int r = 0, b = 0;
    for (auto [u, v] : arr) {
      b += Union(u, v);
    }
    for (auto [u, v] : brr) {
      r += Union(u, v);
    }
    return r + b + 1 == n ? b : INT_MIN;
  };

  while (cin >> n >> m >> k && (n || m || k)) {
    arr.clear(), brr.clear();
    while (m--) {
      char c;
      int u, v;
      cin >> c >> u >> v;
      if (c == 'B') {
        arr.push_back({u, v});
      } else {
        brr.push_back({u, v});
      }
    }
    cout << (Min() <= k && k <= Max()) << "\n";
  }

  return 0;
}
