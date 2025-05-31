// Title : 컨닝 2
// Link  : https://www.acmicpc.net/problem/11014 
// Time  : 48 ms
// Memory: 2772 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, -1},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 1}};

bool room[82][82];
vector<pair<int, int>> edges[82][82];
pair<int, int> conn[82][82];
bool visited[82][82];

bool Traverse(int sy, int sx) {
  for (auto [y, x] : edges[sy][sx]) {
    if (visited[y][x]) continue;
    visited[y][x] = true;
    auto [cy, cx] = conn[y][x];
    if ((cy == 0 && cx == 0) || Traverse(cy, cx)) {
      conn[y][x] = {sy, sx};
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int rows, cols;
    cin >> rows >> cols;

    int ans = 0;
    memset(room, 0, sizeof(room));
    for (int i = 1; i <= rows; i++) {
      for (int j = 1; j <= cols; j++) {
        char c;
        cin >> c;
        ans += (room[i][j] = (c == '.'));
      }
    }

    for (int i = 1; i <= rows; i++) {
      for (int j = 1; j <= cols; j++) {
        edges[i][j].clear();
        if (!room[i][j]) continue;
        for (auto [dy, dx] : kDelta) {
          int y = i + dy;
          int x = j + dx;
          if (!room[y][x]) continue;
          edges[i][j].push_back({y, x});
        }
      }
    }

    memset(conn, 0, sizeof(conn));
    for (int i = 1; i <= rows; i++) {
      for (int j = 1; j <= cols; j += 2) {
        if (!room[i][j]) continue;
        memset(visited, 0, sizeof(visited));
        visited[i][j] = true;
        ans -= Traverse(i, j);
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
