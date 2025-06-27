// Title : 두 단계 최단 경로 1
// Link  : https://www.acmicpc.net/problem/23793 
// Time  : 124 ms
// Memory: 9496 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> edges(n + 1);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
  }

  vector<int> memo;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  auto Push = [&](int x, int w) {
    if (memo[x] <= w) return;
    memo[x] = w;
    pq.push({w, x});
  };

  auto Calc = [&](int st, int en, int mask) {
    memo.assign(n + 1, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tmp;
    pq.swap(tmp);

    Push(st, 0);
    while (!pq.empty()) {
      auto [w, x] = pq.top();
      pq.pop();

      if (memo[x] != w) continue;
      if (x == en) return w;

      for (auto [nxt, ww] : edges[x]) {
        if (nxt == mask) continue;
        Push(nxt, w + ww);
      }
    }

    return -1;
  };

  int x, y, z;
  cin >> x >> y >> z;

  int xz = Calc(x, z, y);
  int xy = Calc(x, y, 0), yz = Calc(y, z, 0);

  cout << (xy != -1 && yz != -1 ? xy + yz : -1) << " "
       << (xz != -1 ? xz : -1);

  return 0;
}
