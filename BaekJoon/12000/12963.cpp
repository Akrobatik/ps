// Title : 달리기
// Link  : https://www.acmicpc.net/problem/12963 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> edges(m);
  for (auto& [u, v] : edges) cin >> u >> v;

  vector<int> table(m + 1);
  table[0] = 1;
  for (int i = 1; i < m; i++) table[i] = (int64_t)table[i - 1] * 3 % kMod;

  vector<int> memo(n);
  iota(memo.begin(), memo.end(), 0);

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
    if (a > b) swap(a, b);
    if (a == 0 && (Find(n - 1) == b)) return true;
    memo[b] = a;
    return false;
  };

  int ans = 0;
  for (int i = m - 1; i >= 0; i--) {
    auto [u, v] = edges[i];
    if (Union(u, v)) {
      if ((ans += table[i]) >= kMod) ans -= kMod;
    }
  }
  cout << ans;

  return 0;
}