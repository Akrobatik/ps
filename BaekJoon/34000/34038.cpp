// Title : 우혁이와 엘리베이터
// Link  : https://www.acmicpc.net/problem/34038 
// Time  : 24 ms
// Memory: 4224 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int64_t, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, e, k, t1, t2;
  cin >> n >> m >> e >> k >> t1 >> t2;

  vector<vector<int>> g(n + 1, vector<int>(n + 1, INT_MAX));
  vector<int> tmp;
  while (m--) {
    int c, t;
    cin >> c >> t;
    tmp.resize(c);
    for (auto& elem : tmp) cin >> elem;
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < c; i++) {
      int mv = tmp[i];
      if (i != 0) {
        int lv = tmp[i - 1];
        g[mv][lv] = g[lv][mv] = min<int>(g[mv][lv], t);
      }
      if (i + 1 != c) {
        int rv = tmp[i + 1];
        g[mv][rv] = g[rv][mv] = min<int>(g[mv][rv], t);
      }
    }
  }

  vector<vector<pair<int, int>>> edges(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (g[i][j] == INT_MAX) continue;
      edges[i].push_back({j, g[i][j]});
    }
  }

  vector<vector<int64_t>> memo(n + 1, vector<int64_t>(k + 1, INT64_MAX));

  priority_queue<tup, vector<tup>, greater<tup>> pq;

  auto Push = [&](int x, int r, int64_t t) {
    if (!(1 <= x && x <= n) || !(0 <= r && r <= k) || memo[x][r] <= t) return;
    memo[x][r] = t;
    pq.push({t, x, r});
  };

  Push(1, 0, 0);
  while (!pq.empty()) {
    auto [ct, cn, ck] = pq.top();
    pq.pop();

    if (memo[cn][ck] != ct) continue;

    if (cn == e) {
      cout << ct;
      return 0;
    }

    int64_t add = (int64_t)t2 * ck + t1;
    Push(cn - 1, ck + 1, ct + add);
    Push(cn + 1, ck + 1, ct + add);

    for (auto [nn, nt] : edges[cn]) {
      add = (int64_t)nt * abs(cn - nn);
      Push(nn, ck, ct + add);
    }
  }
  cout << "-1";

  return 0;
}
