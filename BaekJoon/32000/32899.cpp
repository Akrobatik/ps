// Title : Kruidnoten
// Link  : https://www.acmicpc.net/problem/32899 
// Time  : 268 ms
// Memory: 23488 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;
constexpr long double kEps = 1e-14L;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<pair<int, int>>> g(n + 1);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  bool ok = false;
  vector<pair<int, long double>> arr(k);
  for (auto& [id, prob] : arr) {
    cin >> id >> prob;
    if (abs(prob - 1.0L) < kEps) ok = true;
  }

  if (!ok) {
    cout << "impossible";
    return 0;
  }

  auto Calc = [&](int st) {
    priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;
    vector<int64_t> dist(n + 1, kInf);

    auto Push = [&](int x, int64_t d) {
      if (dist[x] <= d) return;
      dist[x] = d;
      pq.push({d, x});
    };

    Push(st, 0);
    while (!pq.empty()) {
      auto [d, cur] = pq.top();
      pq.pop();

      if (dist[cur] != d) continue;

      for (auto [nxt, w] : g[cur]) {
        Push(nxt, d + w);
      }
    }
    return dist;
  };

  auto da = Calc(1), db = Calc(n);
  sort(arr.begin(), arr.end(), [&](const pair<int, long double>& lhs, const pair<int, long double>& rhs) {
    auto& [li, lp] = lhs;
    auto& [ri, rp] = rhs;
    int64_t lv = da[li] + db[li];
    int64_t rv = da[ri] + db[ri];
    return lv < rv || (lv == rv && lp > rp);
  });

  long double ans = 0.0L;
  long double mul = 1.0L;
  for (auto& [id, prob] : arr) {
    ans += mul * prob * (long double)(da[id] + db[id]);
    mul *= (1.0L - prob);
  }
  cout << setprecision(6) << fixed << ans;

  return 0;
}