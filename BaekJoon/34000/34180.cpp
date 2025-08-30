// Title : 재우의 워터슬라이드
// Link  : https://www.acmicpc.net/problem/34180 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

bool FindPath(int n, int m, int k, int sy, int sx, int ty, int tx, string& out) {
  int lb = abs(sy - ty) + abs(sx - tx) + 1;
  if (((lb + k) & 1) || k < lb) return false;

  vector<pair<int, int>> path;
  path.reserve(n * m);

  auto Inside = [&](int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
  };

  auto Sign = [](int x) {
    return (x > 0) - (x < 0);
  };

  int cy = sy, cx = sx;
  while (cy != ty) {
    path.push_back({cy, cx});
    cy += Sign(ty - cy);
  }
  while (cx != tx) {
    path.push_back({cy, cx});
    cx += Sign(tx - cx);
  }
  path.push_back({ty, tx});

  vector<vector<bool>> used(n, vector<bool>(m));
  for (auto [y, x] : path) used[y][x] = true;

  auto Expand = [&]() {
    int np = path.size();
    for (int i = 1; i < np; i++) {
      auto [y1, x1] = path[i - 1];
      auto [y2, x2] = path[i];

      int oy1 = 0, ox1 = 0, oy2 = 0, ox2 = 0;
      if (y1 == y2) {
        oy1 = -1;
        oy2 = 1;
      } else {
        ox1 = -1;
        ox2 = 1;
      }

      for (int t = 0; t < 2; t++) {
        int oy = t ? oy2 : oy1, ox = t ? ox2 : ox1;
        int yy1 = y1 + oy, xx1 = x1 + ox;
        int yy2 = y2 + oy, xx2 = x2 + ox;
        if (!Inside(yy1, xx1) || !Inside(yy2, xx2)) continue;
        if (used[yy1][xx1] || used[yy2][xx2]) continue;
        used[yy1][xx1] = used[yy2][xx2] = true;
        pair<int, int> p1 = {yy1, xx1}, p2 = {yy2, xx2};
        path.insert(path.begin() + i, {p1, p2});
        return true;
      }
    }
    return false;
  };

  auto Rotate = [&]() {
    int np = path.size();
    for (int i = 2; i < np; i++) {
      auto [y1, x1] = path[i - 2];
      auto [y2, x2] = path[i - 1];
      auto [y3, x3] = path[i];

      if (abs(y3 - y1) != 1 || abs(x3 - x1) != 1) continue;

      int y = y1 ^ y2 ^ y3, x = x1 ^ x2 ^ x3;
      used[y2][x2] = false;
      used[y][x] = true;
      path[i - 1] = {y, x};
      return true;
    }
    return false;
  };

  while (path.size() < k) {
    if (!Expand() && !Rotate()) return false;
  }

  out.clear();
  for (int i = 1; i < path.size(); i++) {
    int dy = path[i].first - path[i - 1].first;
    int dx = path[i].second - path[i - 1].second;
    if (dy == 1) {
      out.push_back('U');
    } else if (dy == -1) {
      out.push_back('D');
    } else if (dx == 1) {
      out.push_back('R');
    } else if (dx == -1) {
      out.push_back('L');
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string path;

  int t;
  cin >> t;
  while (t--) {
    int n, m, k, sy, sx, ty, tx;
    cin >> m >> n >> sx >> sy >> tx >> ty >> k;
    if (FindPath(n, m, k, sy - 1, sx - 1, ty - 1, tx - 1, path)) {
      cout << path << "\n";
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}
