// Title : 호텔
// Link  : https://www.acmicpc.net/problem/1106 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int c, n;
  cin >> c >> n;
  vector<pair<int, int>> arr(n);
  for (auto& [w, r] : arr) cin >> w >> r;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  vector<int> dist(c + 1, INT_MAX);

  auto Push = [&](int w, int r) {
    if (dist[r] <= w) return;
    dist[r] = w;
    pq.push({w, r});
  };

  Push(0, 0);
  while (!pq.empty()) {
    auto [w, r] = pq.top();
    pq.pop();

    if (dist[r] != w) continue;

    for (auto [ww, rr] : arr) {
      Push(w + ww, min<int>(r + rr, c));
    }
  }

  cout << dist[c];

  return 0;
}
