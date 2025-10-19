// Title : 물통
// Link  : https://www.acmicpc.net/problem/2251 
// Time  : 0 ms
// Memory: 9952 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kMove[] = {
    {0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}};

bool vis[201][201][201];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cap[3];
  for (auto& e : cap) cin >> e;

  queue<array<int, 3>> q;

  auto Push = [&](int x, int y, int z) {
    if (vis[x][y][z]) return;
    vis[x][y][z] = true;
    q.push({x, y, z});
  };

  Push(0, 0, cap[2]);
  while (!q.empty()) {
    auto xyz = q.front();
    q.pop();

    for (auto [src, dst] : kMove) {
      int cut = min<int>(cap[dst] - xyz[dst], xyz[src]);
      auto nxt = xyz;
      nxt[src] -= cut, nxt[dst] += cut;
      Push(nxt[0], nxt[1], nxt[2]);
    }
  }

  for (int i = 0; i <= cap[2]; i++) {
    if (vis[0][cap[2] - i][i]) {
      cout << i << " ";
    }
  }

  return 0;
}