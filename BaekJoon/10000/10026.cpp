// Title : 적록색약
// Link  : https://www.acmicpc.net/problem/10026
// Time  : 0 ms
// Memory: 2036 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

int n;
char cells[100][100];

int Normal() {
  bool memo[100][100];
  memset(memo, 0, sizeof(memo));

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (memo[i][j]) continue;
      ++cnt;
      char color = cells[i][j];
      queue<pair<int, int>> q;
      memo[i][j] = true;
      q.push({i, j});
      while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (auto [dy, dx] : kDelta) {
          int yy = y + dy, xx = x + dx;
          if (0 <= yy & yy < n && 0 <= xx && xx < n && !memo[yy][xx] && cells[yy][xx] == color) {
            memo[yy][xx] = true;
            q.push({yy, xx});
          }
        }
      }
    }
  }

  return cnt;
}

int RGBlind() {
  bool memo[100][100];
  memset(memo, 0, sizeof(memo));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (cells[i][j] == 'G') cells[i][j] = 'R';
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (memo[i][j]) continue;
      ++cnt;
      char color = cells[i][j];
      queue<pair<int, int>> q;
      memo[i][j] = true;
      q.push({i, j});
      while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (auto [dy, dx] : kDelta) {
          int yy = y + dy, xx = x + dx;
          if (0 <= yy & yy < n && 0 <= xx && xx < n && !memo[yy][xx] && cells[yy][xx] == color) {
            memo[yy][xx] = true;
            q.push({yy, xx});
          }
        }
      }
    }
  }

  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> cells[i][j];
    }
  }

  int v1 = Normal();
  int v2 = RGBlind();
  cout << v1 << " " << v2;

  return 0;
}
