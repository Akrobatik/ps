// Title : 토마토
// Link  : https://www.acmicpc.net/problem/7576
// Time  : 72 ms
// Memory: 6108 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

short memo[1000][1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  queue<int> q;
  int n, m;
  cin >> m >> n;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      cin >> memo[y][x];
      if (memo[y][x] == 1) q.push((y << 16) | x);
    }
  }

  int rem = 0;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      rem += memo[y][x] == 0;
    }
  }

  int i;
  for (i = 0; rem && !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto yx = q.front();
      q.pop();

      int y = yx >> 16, x = yx & 0xFFFF;
      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy & yy < n && 0 <= xx && xx < m && !memo[yy][xx]) {
          --rem;
          memo[yy][xx] = true;
          q.push((yy << 16) | xx);
        }
      }
    }
  }

  cout << (rem ? -1 : i);

  return 0;
}
