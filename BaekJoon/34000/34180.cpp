// Title : 재우의 워터슬라이드
// Link  : https://www.acmicpc.net/problem/34180 
// Time  : 0 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

bool FindPath(int n, int m, int k, int sy, int sx, int ty, int tx, string& out) {
  out.clear();

  int lb = abs(sy - ty) + abs(sx - tx) + 1;
  if (((lb + k) & 1) || k < lb) return false;

  auto Inside = [&](int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
  };

  auto Sign = [](int x) {
    return (x > 0) - (x < 0);
  };

  auto Adj = [&](const pair<int, int>& a, const pair<int, int>& b) {
    auto [ay, ax] = a;
    auto [by, bx] = b;
    return abs(ay - by) + abs(ax - bx) == 1;
  };

  vector<pair<int, int>> tmp;
  tmp.reserve(n * m);
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      for (int j = m - 1; j >= 0; j--) tmp.push_back({i, j});
    } else {
      for (int j = 0; j < m; j++) tmp.push_back({i, j});
    }
  }

  int sid = (sy & 1) ? sy * m + (m - 1 - sx) : sy * m + sx;
  int tid = (ty & 1) ? ty * m + (m - 1 - tx) : ty * m + tx;

  vector<pair<int, int>> path;
  path.reserve(abs(sid - tid) + 1);
  if (sid <= tid) {
    for (int i = sid; i <= tid; i++) path.push_back(tmp[i]);
  } else {
    for (int i = sid; i >= tid; i--) path.push_back(tmp[i]);
  }

  vector<vector<bool>> used(n, vector<bool>(m));
  for (auto [y, x] : path) used[y][x] = true;

  auto Expand = [&]() {
    int np = path.size();
    for (int i = 0; i + 1 < np; i++) {
      auto [ay, ax] = path[i];
      auto [by, bx] = path[i + 1];

      int oy1 = 0, ox1 = 0, oy2 = 0, ox2 = 0;
      if (ax == bx) {
        ox1 = -1;
        ox2 = 1;
      } else {
        oy1 = -1;
        oy2 = 1;
      }

      for (int t = 0; t < 2; t++) {
        int oy = t ? oy2 : oy1, ox = t ? ox2 : ox1;
        if (!Inside(ay + oy, ax + ox) || !Inside(by + oy, bx + ox)) continue;
        if (used[ay + oy][ax + ox] || used[by + oy][bx + ox]) continue;
        used[ay + oy][ax + ox] = used[by + oy][bx + ox] = true;
        path.insert(path.begin() + i + 1, {make_pair(ay + oy, ax + ox), make_pair(by + oy, bx + ox)});
        return true;
      }
    }
    return false;
  };

  auto Shrink = [&]() {
    int np = path.size();
    for (int i = 1; i + 2 < np; i++) {
      auto v0 = path[i - 1], v1 = path[i], v2 = path[i + 1], v3 = path[i + 2];
      int dx1 = v1.second - v0.second, dy1 = v1.first - v0.first;
      int dx2 = v2.second - v1.second, dy2 = v2.first - v1.first;
      int dx3 = v3.second - v2.second, dy3 = v3.first - v2.first;

      bool opp = (dx1 == -dx3 && dy1 == -dy3 && (abs(dx1) + abs(dy1) == 1));
      bool orth = ((abs(dx2) + abs(dy2) == 1) && !(dx1 == dx2 && dy1 == dy2) && !(dx1 == -dx2 && dy1 == -dy2));
      if (opp && orth) {
        if (!Adj(v0, v3)) continue;
        path.erase(path.begin() + i, path.begin() + i + 2);
        return true;
      }
    }
    return false;
  };

  while (Expand());

  while (path.size() > k) {
    if (!Shrink()) return false;
  }

  if (path.size() != k) return false;
  if ((path[0].first != sy || path[0].second != sx) || (path.back().first != ty || path.back().second != tx)) return false;

  for (int i = 1; i < path.size(); i++) {
    if (!Inside(path[i].first, path[i].second)) return false;
    if (!Adj(path[i - 1], path[i])) return false;
  }

  vector<vector<bool>> visited(n, vector<bool>(m));
  for (auto [y, x] : path) {
    if (visited[y][x]) return false;
    visited[y][x] = true;
  }

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
    int n, m, xs, ys, xf, yf, k;
    cin >> n >> m >> xs >> ys >> xf >> yf >> k;
    if (FindPath(m, n, k, ys - 1, xs - 1, yf - 1, xf - 1, path)) {
      cout << path << "\n";
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}
