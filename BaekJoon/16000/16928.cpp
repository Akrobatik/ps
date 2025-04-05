// Title : 뱀과 사다리 게임
// Link  : https://www.acmicpc.net/problem/16928
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool memo[101] = {};
  int warp[101];
  iota(warp + 1, warp + 101, 1);

  int n, m;
  cin >> n >> m;
  int nm = n + m;
  while (nm--) {
    int u, v;
    cin >> u >> v;
    warp[u] = v;
  }

  auto Find = [&](int id) {
    while (id != warp[id]) id = warp[id] = warp[warp[id]];
    return id;
  };

  queue<int> q;
  memo[1] = true;
  q.push(1);
  int cnt;
  for (cnt = 0; !memo[100]; cnt++) {
    int nq = q.size();
    while (nq--) {
      auto cur = q.front();
      q.pop();

      for (int i = 1; i <= 6; i++) {
        if (cur + i > 100) continue;
        auto nxt = Find(cur + i);
        if (!memo[nxt]) {
          memo[nxt] = true;
          q.push(nxt);
        }
      }
    }
  }
  cout << cnt;

  return 0;
}
