// Title : 나이트 투어
// Link  : https://www.acmicpc.net/problem/1331 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

pair<int, int> Read() {
  char a, b;
  cin >> a >> b;
  return {a - 'A', b - '1'};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool visited[6][6] = {};

  auto [x, y] = Read();
  int sx = x, sy = y;
  visited[x][y] = true;
  for (int i = 1; i < 36; i++) {
    auto [nx, ny] = Read();

    if (visited[nx][ny]) {
      cout << "Invalid";
      return 0;
    }
    visited[nx][ny] = true;

    bool ok = false;
    for (auto [dx, dy] : kDelta) {
      int xx = x + dx, yy = y + dy;
      if (xx == nx && yy == ny) ok = true;
    }
    if (!ok) {
      cout << "Invalid";
      return 0;
    }

    x = nx, y = ny;
  }

  bool ok = false;
  for (auto [dx, dy] : kDelta) {
    int xx = sx + dx, yy = sy + dy;
    if (xx == x && yy == y) ok = true;
  }
  cout << (ok ? "Valid" : "Invalid");

  return 0;
}
