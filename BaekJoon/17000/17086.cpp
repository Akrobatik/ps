// Title : 아기 상어 2
// Link  : https://www.acmicpc.net/problem/17086
// Time  : 0 ms
// Memory: 2164 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}};

int memo[50][50];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> memo[i][j];
      if (memo[i][j]) q.push({i, j});
    }
  }

  int i;
  for (i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto [y, x] = q.front();
      q.pop();

      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy && yy < n && 0 <= xx && xx < m && !memo[yy][xx]) {
          memo[yy][xx] = i + 1;
          q.push({yy, xx});
        }
      }
    }
  }
  cout << i - 1;

  return 0;
}
