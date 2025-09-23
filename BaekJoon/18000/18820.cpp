// Title : Karaoke Meetup
// Link  : https://www.acmicpc.net/problem/18820 
// Time  : 184 ms
// Memory: 27492 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<bool> check(n + 1);
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    check[x] = true;
  }

  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  vector<int64_t> mind(n + 1, kInf);
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;

  auto Push = [&](int x, int64_t d) {
    if (mind[x] <= d) return;
    mind[x] = d;
    pq.push({d, x});
  };

  for (int i = 1; i <= n; i++) {
    if (check[i]) Push(i, 0);
  }

  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();

    if (mind[cur] != d) continue;

    for (auto [nxt, w] : g[cur]) {
      Push(nxt, d + w);
    }
  }

  auto FindMax = [&](int node) {
    int mi;
    int64_t maxd = -1;

    [&](this auto&& self, int cur, int par, int64_t d) -> void {
      if (check[cur] && maxd < d) maxd = d, mi = cur;

      for (auto [nxt, w] : g[cur]) {
        if (nxt == par) continue;
        self(nxt, cur, d + w);
      }
    }(node, 0, 0);

    return mi;
  };

  int node = 1;
  while (!check[node]) ++node;

  int st = FindMax(node);
  int en = FindMax(st);

  vector<int64_t> maxd(n + 1);

  auto Calc = [&](int node) {
    [&](this auto&& self, int cur, int par, int64_t d) -> void {
      maxd[cur] = max<int64_t>(maxd[cur], d);

      for (auto [nxt, w] : g[cur]) {
        if (nxt == par) continue;
        self(nxt, cur, d + w);
      }
    }(node, 0, 0);
  };

  Calc(st), Calc(en);

  int64_t p = 0, q = 1;
  for (int i = 1; i <= n; i++) {
    int64_t np = mind[i], nq = maxd[i];
    if ((__int128_t)p * nq < (__int128_t)np * q) p = np, q = nq;
  }

  int64_t gc = GCD(p, q);
  cout << p / gc << "/" << q / gc;

  return 0;
}