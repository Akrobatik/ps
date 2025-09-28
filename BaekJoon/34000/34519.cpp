// Title : 바보
// Link  : https://www.acmicpc.net/problem/34519 
// Time  : 288 ms
// Memory: 20744 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;

  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;
  vector<int64_t> dist(n, kInf);
  vector<bool> vis(n);

  auto Push = [&](int x, int64_t d) {
    if (dist[x] <= d) return;
    dist[x] = d;
    pq.push({d, x});
  };

  for (int i = 0; i < n; i++) {
    Push(i, arr[i]);
  }

  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();

    if (dist[cur] != d) continue;

    vis[cur] = true;
    for (int delta : {-1, 1}) {
      int nxt = cur + delta;
      if (!(0 <= nxt && nxt < n)) continue;

      int cnt = (0 <= nxt - 1 && nxt - 1 < n && vis[nxt - 1]) + (0 <= nxt + 1 && nxt + 1 < n && vis[nxt + 1]);
      int64_t add = arr[nxt] >> cnt;
      Push(nxt, d + add);
    }
  }
  cout << *max_element(dist.begin(), dist.end());

  return 0;
}