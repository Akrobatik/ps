// Title : 미로 탐색
// Link  : https://www.acmicpc.net/problem/2178
// Time  : 0 ms
// Memory: 2164 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

bool memo[101][101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      memo[i][j] = c == '0';
    }
  }

  queue<pair<int, int>> q;
  memo[1][1] = true;
  q.push({1, 1});
  int cnt;
  for (cnt = 1; !memo[n][m]; cnt++) {
    int nq = q.size();
    while (nq--) {
      auto [y, x] = q.front();
      q.pop();

      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (1 <= yy && yy <= n && 1 <= xx && xx <= m && !memo[yy][xx]) {
          memo[yy][xx] = true;
          q.push({yy, xx});
        }
      }
    }
  }
  cout << cnt;

  return 0;
}
