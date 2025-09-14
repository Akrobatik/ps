// Title : Last Man Standing
// Link  : https://www.acmicpc.net/problem/34331 
// Time  : 148 ms
// Memory: 12316 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<vector<int>> mat(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> mat[i][j];
    }
  }

  vector<pair<int, int>> arr;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      arr.push_back({i, j});
    }
  }

  sort(arr.begin(), arr.end(), [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    auto [li, lj] = lhs;
    auto [ri, rj] = rhs;
    return mat[li][lj] > mat[ri][rj];
  });

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

  int rem = n - k;
  int64_t sum = 0;
  vector<vector<int>> edges(n + 1);
  for (auto [a, b] : arr) {
    if (Union(a, b)) {
      sum += mat[a][b];
      edges[a].push_back(b), edges[b].push_back(a);
      if (--rem == 0) break;
    }
  }

  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; i++) {
    if (i != memo[i]) continue;

    [&](this auto&& self, int cur, int par) -> void {
      for (auto nxt : edges[cur]) {
        if (nxt == par) continue;
        self(nxt, cur);
        ans.push_back({cur, nxt});
      }
    }(i, 0);
  }

  cout << sum << "\n";
  for (auto [a, b] : ans) {
    cout << a << " " << b << "\n";
  }

  return 0;
}
