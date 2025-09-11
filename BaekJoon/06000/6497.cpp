// Title : 전력난
// Link  : https://www.acmicpc.net/problem/6497 
// Time  : 236 ms
// Memory: 4520 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  while (cin >> n >> m && n && m) {
    int all = 0;
    vector<tuple<int, int, int>> arr(m);
    for (auto& [w, u, v] : arr) cin >> u >> v >> w, all += w;
    sort(arr.begin(), arr.end());

    vector<int> memo(n + 1);
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
      memo[b] = a;
      return true;
    };

    int sum = 0;
    for (auto [w, u, v] : arr) {
      if (Union(u, v)) sum += w;
    }

    cout << all - sum << "\n";
  }

  return 0;
}
