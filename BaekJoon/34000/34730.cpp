// Title : 그래도 시간은 흐른다
// Link  : https://www.acmicpc.net/problem/34730 
// Time  : 348 ms
// Memory: 189632 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int64_t, int, int>;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k, s, t;
  cin >> n >> m >> k >> s >> t;

  vector<array<vector<pair<int, int>>, 30>> g(n + 1);
  while (m--) {
    int u, v, w, x;
    cin >> u >> v >> w >> x;
    for (int i = 0; i < k; i += x) {
      g[u][i].push_back({v, w});
    }
  }

  array<int64_t, 30> init;
  init.fill(kInf);
  vector<array<int64_t, 30>> memo(n + 1, init);
  priority_queue<tup, vector<tup>, greater<tup>> pq;

  auto Push = [&](int u, int x, int64_t d) {
    if (memo[u][x] <= d) return;
    memo[u][x] = d;
    pq.push({d, u, x});
  };

  Push(s, 0, 0);
  while (!pq.empty()) {
    auto [d, u, x] = pq.top();
    pq.pop();

    if (memo[u][x] != d) continue;

    for (auto [v, w] : g[u][x]) {
      Push(v, (x + w) % k, d + w);
    }
  }

  int64_t minn = *min_element(memo[t].begin(), memo[t].end());
  cout << (minn != kInf ? minn : -1);

  return 0;
}