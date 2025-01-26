#include <bits/stdc++.h>

using namespace std;

int n;
int m[20][20];
bool visited[20][20];
int sy, sx, ss = 2, sc;

void GrowShark(int ty, int tx) {
  m[ty][tx] = 9;
  m[sy][sx] = 0;
  sy = ty;
  sx = tx;
  if (++sc == ss) sc = 0, ss++;
}

int Traverse() {
  memset(visited, 0, sizeof(visited));
  vector<tuple<int, int, int>> targets;
  queue<tuple<int, int, int>> q;
  q.push({0, sy, sx});
  while (!q.empty()) {
    auto [cost, y, x] = q.front();
    q.pop();

    if (visited[y][x]) continue;
    visited[y][x] = true;

    if (m[y][x] && m[y][x] < ss && (y != sy || x != sx)) targets.push_back({cost, y, x});

    static constexpr int dy[] = {0, 0, 1, -1};
    static constexpr int dx[] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++) {
      int yy = y + dy[i];
      int xx = x + dx[i];
      if (0 <= yy && yy < n && 0 <= xx && xx < n && m[yy][xx] <= ss && !visited[yy][xx]) {
        q.push({cost + 1, yy, xx});
      }
    }
  }

  if (targets.empty()) return 0;

  sort(targets.begin(), targets.end());
  auto [tc, ty, tx] = targets.front();
  GrowShark(ty, tx);
  return tc;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> m[i][j];
      if (m[i][j] == 9) sy = i, sx = j;
    }
  }

  int ans = 0;
  while (int cnt = Traverse()) ans += cnt;
  cout << ans << endl;

  return 0;
}
