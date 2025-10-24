// Title : Cup of Tea
// Link  : https://www.acmicpc.net/problem/33181 
// Time  : 244 ms
// Memory: 60548 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int64_t, int64_t, int>;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;

  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  vector<int> mask(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> mask[i];
  }

  vector<int64_t> dist(n + 1, kInf);
  vector<map<int64_t, int64_t, greater<int64_t>>> memo(n + 1);

  auto Push = [&](int i, int64_t d, int64_t r) {
    auto& mp = memo[i];
    auto it = mp.lower_bound(d);
    if (it != mp.end() && it->second >= r) return false;

    while (it != mp.begin() && prev(it)->second <= r) it = mp.erase(prev(it));
    mp[d] = r;
    return true;
  };

  auto Cmp = [](const tup& lhs, const tup& rhs) {
    auto [ld, lr, li] = lhs;
    auto [rd, rr, ri] = rhs;
    if (ld != rd) return ld > rd;
    if (lr != rr) return lr < rr;
    return li < ri;
  };

  priority_queue<tup, vector<tup>, decltype(Cmp)> pq(Cmp);
  pq.push({0, k, 1});

  while (!pq.empty()) {
    auto [d, r, cur] = pq.top();
    pq.pop();

    if (mask[cur]) r = k;
    if (!Push(cur, d, r)) continue;
    dist[cur] = min<int64_t>(dist[cur], d);

    for (auto [nxt, w] : g[cur]) {
      int64_t nd = d + w, nr = r - w;
      if (nr < 0) continue;
      pq.push({nd, nr, nxt});
    }
  }

  for (int i = 2; i <= n; i++) {
    cout << (dist[i] != kInf ? dist[i] : -1) << " ";
  }

  return 0;
}