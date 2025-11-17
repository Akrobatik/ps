// Title : Between
// Link  : https://www.acmicpc.net/problem/34698 
// Time  : 148 ms
// Memory: 18072 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }

  vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
  for (int i = 1; i <= n; i++) {
    queue<int> q;

    auto Push = [&](int x, int d) {
      if (memo[i][x] != -1) return;
      memo[i][x] = d;
      q.push(x);
    };

    Push(i, 0);
    for (int d = 1; !q.empty(); d++) {
      int nq = q.size();
      while (nq--) {
        int cur = q.front();
        q.pop();

        for (auto nxt : g[cur]) {
          Push(nxt, d);
        }
      }
    }
  }

  vector<int> arr;

  int q;
  cin >> q;
  while (q--) {
    int a, b, k;
    cin >> a >> b >> k;

    if (k > 0) {
      arr.resize(k);
      for (auto& e : arr) cin >> e;
      sort(arr.begin(), arr.end(), [&](int lhs, int rhs) {
        return memo[a][lhs] < memo[a][rhs];
      });

      if (memo[a][arr.back()] >= memo[a][b]) {
        cout << "NO\n";
        continue;
      }
    } else {
      arr.clear();
    }

    arr.push_back(b);
    if (memo[a][arr[0]] < 0) {
      cout << "NO\n";
      continue;
    }

    bool ok = true;
    for (int i = 1; i <= k; i++) {
      int u = arr[i - 1], v = arr[i];
      int dt = memo[u][v];
      if (dt == -1) {
        ok = false;
        break;
      }

      if (memo[a][u] + dt != memo[a][v]) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}