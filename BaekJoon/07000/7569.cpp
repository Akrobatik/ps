// Title : 토마토
// Link  : https://www.acmicpc.net/problem/7569
// Time  : 88 ms
// Memory: 4592 KB

#include <bits/stdc++.h>

using namespace std;

constexpr tuple<int, int, int> kDelta[] = {
    {-1, 0, 0},
    {1, 0, 0},
    {0, -1, 0},
    {0, 1, 0},
    {0, 0, -1},
    {0, 0, 1}};

bool memo[100][100][100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, h;
  cin >> m >> n >> h;
  int rem = 0;
  queue<tuple<int, int, int>> q;
  for (int z = 0; z < h; z++) {
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < m; x++) {
        int v;
        cin >> v;
        if (v == 1) {
          memo[z][y][x] = true;
          q.push({z, y, x});
        } else if (v == 0) {
          ++rem;
        } else {
          memo[z][y][x] = true;
        }
      }
    }
  }

  int i;
  for (i = 0; rem && !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto [z, y, x] = q.front();
      q.pop();

      for (auto [dz, dy, dx] : kDelta) {
        int zz = z + dz, yy = y + dy, xx = x + dx;
        if (0 <= zz && zz < h && 0 <= yy & yy < n && 0 <= xx && xx < m && !memo[zz][yy][xx]) {
          --rem;
          memo[zz][yy][xx] = true;
          q.push({zz, yy, xx});
        }
      }
    }
  }

  if (rem) {
    cout << "-1";
  } else {
    cout << i;
  }

  return 0;
}
