// Title : 헌내기는 친구가 필요해
// Link  : https://www.acmicpc.net/problem/21736
// Time  : 12 ms
// Memory: 3340 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

bool walls[600][600];
bool mans[600][600];
bool visited[600][600];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int cy, cx;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      walls[i][j] = (c == 'X');
      mans[i][j] = (c == 'P');
      if (c == 'I') cy = i, cx = j;
    }
  }

  int ans = 0;
  queue<pair<int, int>> q;
  visited[cy][cx] = true;
  q.push({cy, cx});
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();

    ans += mans[y][x];
    for (auto [dy, dx] : kDelta) {
      int yy = y + dy, xx = x + dx;
      if (0 <= yy && yy < n && 0 <= xx && xx < m && !walls[yy][xx] && !visited[yy][xx]) {
        visited[yy][xx] = true;
        q.push({yy, xx});
      }
    }
  }

  if (ans) {
    cout << ans;
  } else {
    cout << "TT";
  }

  return 0;
}
