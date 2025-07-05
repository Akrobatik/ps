// Title : 트리
// Link  : https://www.acmicpc.net/problem/4803 
// Time  : 24 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> memo;
  vector<bool> ok;

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
    if (a == b || !ok[b]) ok[a] = false;
  };

  int n, m, t = 0;
  while (cin >> n >> m && (n || m)) {
    memo.resize(n + 1);
    iota(memo.begin(), memo.end(), 0);
    ok.assign(n + 1, true);

    while (m--) {
      int u, v;
      cin >> u >> v;
      Union(u, v);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += (memo[i] == i && ok[i]);
    }
    cout << "Case " << ++t << ": ";
    if (cnt == 0) {
      cout << "No trees.\n";
    } else if (cnt == 1) {
      cout << "There is one tree.\n";
    } else {
      cout << "A forest of " << cnt << " trees.\n";
    }
  }

  return 0;
}
