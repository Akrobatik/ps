// Title : Grid travel
// Link  : https://www.acmicpc.net/problem/27693 
// Time  : 8 ms
// Memory: 2496 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int Color(int y, int x) {
  return (y + x) & 1;
}

bool ColorCompatible(int n, int m, int sy, int sx, int ty, int tx) {
  if (n * m % 2 == 0) return Color(sy, sx) != Color(ty, tx);
  return Color(sy, sx) == 0 && Color(ty, tx) == 0;
}

bool CheckF1(int n, int m, int sy, int sx, int ty, int tx) {
  if (n == 1) {
    bool sb = (sx == 1 || sx == m);
    bool tb = (tx == 1 || tx == m);
    return !sb || !tb;
  }

  if (m == 1) {
    bool sb = (sy == 1 || sy == n);
    bool tb = (ty == 1 || ty == n);
    return !sb || !tb;
  }

  return false;
}

bool CheckF2(int n, int m, int sy, int sx, int ty, int tx) {
  if (abs(sy - ty) + abs(sx - tx) != 1) return false;
  if (n == 2) return !(sy == ty || (sx == 1 && tx == 1) || (sx == m && tx == m));
  if (m == 2) return !(sx == tx || (sy == 1 && ty == 1) || (sy == n && ty == n));
  return false;
}

bool CheckF2S(int n, int m, int sy, int sx, int ty, int tx) {
  if (min<int>(n, m) != 2) return false;

  int rn = n, rm = m;
  int rsy = sy, rsx = sx;
  int rty = ty, rtx = tx;
  if (rn > rm) swap(rn, rm), swap(rsy, rsx), swap(rty, rtx);
  if (rsx > rtx) swap(rsy, rty), swap(rsx, rtx);
  return (rsx == rtx) || (rsx == rtx - 1 && rsy != rty);
}

bool CheckF3(int n, int m, int sy, int sx, int ty, int tx) {
  if (min<int>(n, m) != 3) return false;

  int rn = n, rm = m;
  int rsy = sy, rsx = sx;
  int rty = ty, rtx = tx;
  if (rn > rm) swap(rn, rm), swap(rsy, rsx), swap(rty, rtx);
  if (rsx > rtx) swap(rsy, rty), swap(rsx, rtx);
  if ((rm & 1) || Color(rsy, rsx) != 1 || Color(rty, rtx) != 0) return false;
  return (rsy == 2 && rsx < rtx) || (rsy != 2 && rsx < rtx - 1);
}

bool CheckC0(int n, int m, int sy, int sx, int ty, int tx) {
  return ColorCompatible(n, m, sy, sx, ty, tx) && !CheckF1(n, m, sy, sx, ty, tx) && !CheckF2(n, m, sy, sx, ty, tx) && !CheckF3(n, m, sy, sx, ty, tx);
}

bool CheckC1(int n, int m, int sy, int sx, int ty, int tx) {
  bool even = ((n * m) % 2 == 0);
  bool same = (Color(sy, sx) == Color(ty, tx));
  return !CheckF1(n, m, sy, sx, ty, tx) && !CheckF2S(n, m, sy, sx, ty, tx) && ((even && same) || (!even && !same));
}

bool CheckC2(int n, int m, int sy, int sx, int ty, int tx) {
  bool odd = ((n * m) % 2 == 1);
  bool black = (Color(sy, sx) == 1 && Color(ty, tx) == 1);
  if (odd && black && !CheckF1(n, m, sy, sx, ty, tx) && !CheckF2S(n, m, sy, sx, ty, tx)) return true;
  if (ColorCompatible(n, m, sy, sx, ty, tx) && CheckF3(n, m, sy, sx, ty, tx)) return true;
  return false;
}

int CalcUpperBound(int n, int m, int sy, int sx, int ty, int tx) {
  int rn = n, rm = m;
  int rsy = sy, rsx = sx;
  int rty = ty, rtx = tx;
  if (rn > rm) swap(rn, rm), swap(rsy, rsx), swap(rty, rtx);
  if (rsx > rtx) swap(rsy, rty), swap(rsx, rtx);

  if (rsy == rty && rsx == rtx) return 1;
  if (CheckF1(n, m, sy, sx, ty, tx)) return rtx - rsx + 1;
  if (CheckF2S(n, m, sy, sx, ty, tx)) return max<int>(rsx + rtx, rm * 2 - rtx - rsx + 2);
  if (CheckC0(n, m, sy, sx, ty, tx)) return n * m;
  if (CheckC1(n, m, sy, sx, ty, tx)) return n * m - 1;
  if (CheckC2(n, m, sy, sx, ty, tx)) return n * m - 2;
  return 0;
}

list<pair<int, int>> BuildLongestPath(int n, int m, int sy, int sx, int ty, int tx);

bool TryStrip(int n, int m, int sy, int sx, int ty, int tx, list<pair<int, int>>& path) {
  path.clear();

  int ub = CalcUpperBound(n, m, sy, sx, ty, tx);

  auto Check = [&](int mrg) {
    switch (mrg) {
      case 0: {
        return (ty <= n - 2 && ub == CalcUpperBound(n - 2, m, sy, sx, ty, tx) + m * 2);
      } break;
      case 1: {
        return (sy >= 3 && ub == CalcUpperBound(n - 2, m, sy - 2, sx, ty - 2, tx) + m * 2);
      } break;
      case 2: {
        return (tx <= m - 2 && ub == CalcUpperBound(n, m - 2, sy, sx, ty, tx) + n * 2);
      } break;
      case 3: {
        return (sx >= 3 && ub == CalcUpperBound(n, m - 2, sy, sx - 2, ty, tx - 2) + n * 2);
      } break;
    }
    return false;
  };

  for (int mrg = 0; mrg < 4; mrg++) {
    if (!Check(mrg)) continue;

    if (mrg <= 1) {
      int dy = (mrg == 1 ? 2 : 0);
      path = BuildLongestPath(n - 2, m, sy - dy, sx, ty - dy, tx);
      for (auto& [y, x] : path) y += dy;

      int by = (mrg == 1 ? 3 : n - 2);
      int ny1 = (mrg == 1 ? 2 : n - 1), ny2 = (mrg == 1 ? 1 : n);
      for (auto it = next(path.begin()); it != path.end(); ++it) {
        auto [y1, x1] = *prev(it);
        auto [y2, x2] = *it;
        if (y1 != by || y2 != by) continue;

        if (x1 < x2) {
          for (int x = x1; x >= 1; x--) path.insert(it, {ny1, x});
          for (int x = 1; x <= m; x++) path.insert(it, {ny2, x});
          for (int x = m; x >= x2; x--) path.insert(it, {ny1, x});
        } else {
          for (int x = x1; x <= m; x++) path.insert(it, {ny1, x});
          for (int x = m; x >= 1; x--) path.insert(it, {ny2, x});
          for (int x = 1; x <= x2; x++) path.insert(it, {ny1, x});
        }
        break;
      }
    } else {
      int dx = (mrg == 3 ? 2 : 0);
      path = BuildLongestPath(n, m - 2, sy, sx - dx, ty, tx - dx);
      for (auto& [y, x] : path) x += dx;

      int bx = (mrg == 3 ? 3 : m - 2);
      int nx1 = (mrg == 3 ? 2 : m - 1), nx2 = (mrg == 3 ? 1 : m);
      for (auto it = next(path.begin()); it != path.end(); ++it) {
        auto [y1, x1] = *prev(it);
        auto [y2, x2] = *it;
        if (x1 != bx || x2 != bx) continue;

        if (y1 < y2) {
          for (int y = y1; y >= 1; y--) path.insert(it, {y, nx1});
          for (int y = 1; y <= n; y++) path.insert(it, {y, nx2});
          for (int y = n; y >= y2; y--) path.insert(it, {y, nx1});
        } else {
          for (int y = y1; y <= n; y++) path.insert(it, {y, nx1});
          for (int y = n; y >= 1; y--) path.insert(it, {y, nx2});
          for (int y = 1; y <= y2; y++) path.insert(it, {y, nx1});
        }
        break;
      }
    }

    return true;
  }

  return false;
}

bool TrySplit(int n, int m, int sy, int sx, int ty, int tx, list<pair<int, int>>& path) {
  auto MergeV = [&](int cut_col, int y_row) {
    auto pl = BuildLongestPath(n, cut_col, sy, sx, y_row, cut_col);
    auto pr = BuildLongestPath(n, m - cut_col, y_row, 1, ty, tx - cut_col);
    for (auto [y, x] : pl) path.push_back({y, x});
    for (auto [y, x] : pr) path.push_back({y, x + cut_col});
  };

  auto MergeH = [&](int cut_row, int x_col) {
    auto pt = BuildLongestPath(cut_row, m, sy, sx, cut_row, x_col);
    auto pb = BuildLongestPath(n - cut_row, m, 1, x_col, ty - cut_row, tx);
    for (auto [y, x] : pt) path.push_back({y, x});
    for (auto [y, x] : pb) path.push_back({y + cut_row, x});
  };

  path.clear();

  if (n <= 2 || m <= 2) return false;
  if (n == 3 && m == 3) return false;
  if (n == 4 && m == 5) return false;

  int ub = CalcUpperBound(n, m, sy, sx, ty, tx);
  if (sx <= 2 && tx >= m - 1) {
    if (m > 4 && n >= 4) {
      int color = Color(sy, sx) ^ 1;
      int base = (color ? 1 : 2);
      int y = base;
      if (sx == 1 && y == sy) y += 2;
      if (y > n) y = base + 2;
      MergeV(2, y);
    } else if (m >= 4 && n == 3) {
      for (int y = 1; y <= 3; y++) {
        int ul = CalcUpperBound(n, 2, sy, sx, y, 2);
        int ur = CalcUpperBound(n, m - 2, y, 1, ty, tx - 2);
        if (ub == ul + ur) {
          MergeV(2, y);
          break;
        }
      }
    } else if (m == 4 && n == 4) {
      if ((sy == 1 && sx == 2 && ty == 4 && tx == 3) ||
          (sy == 4 && sx == 2 && ty == 1 && tx == 3)) {
        MergeV(2, 2);
      } else {
        int ul = CalcUpperBound(4, 2, sy, sx, 1, 2);
        int ur = CalcUpperBound(4, 2, 1, 1, ty, tx - 2);
        if (ub == ul + ur) {
          MergeV(2, 1);
        } else {
          MergeV(2, 4);
        }
      }
    } else {
      return false;
    }
  } else if (n == 4 && m == 4) {
    bool vflip = false;
    if (sy > 2) sy = 5 - sy, ty = 5 - ty, vflip = true;

    if ((sy == 2 && sx == 1 && ty == 3 && tx == 4) ||
        (sy == 2 && sx == 4 && ty == 3 && tx == 1)) {
      MergeH(2, 2);
    } else {
      int ul = CalcUpperBound(2, 4, sy, sx, 2, 1);
      int ur = CalcUpperBound(2, 4, 1, 1, ty - 2, tx);
      if (ub == ul + ur) {
        MergeH(2, 1);
      } else {
        MergeH(2, 4);
      }
    }

    if (vflip) {
      for (auto& [y, x] : path) y = 5 - y;
    }
  } else {
    assert(0);
  }
  return true;
}

list<pair<int, int>> BuildLongestPathInternal(int n, int m, int sy, int sx, int ty, int tx) {
  list<pair<int, int>> path;
  if (n == 1) {
    for (int x = sx; x <= tx; x++) {
      path.push_back({sy, x});
    }
    return path;
  }

  if (n == 2) {
    if (CheckF2S(n, m, sy, sx, ty, tx)) {
      int lsz = sx + tx, rsz = m * 2 - tx - sx + 2;
      if (lsz >= rsz) {
        for (int i = sx; i >= 1; i--) path.push_back({sy, i});
        for (int i = 1; i <= tx; i++) path.push_back({ty, i});
      } else {
        for (int i = sx; i <= m; i++) path.push_back({sy, i});
        for (int i = m; i >= tx; i--) path.push_back({ty, i});
      }
    } else {
      if (sy == ty) {
        for (int i = sx; i >= 1; i--) path.push_back({sy, i});
        for (int i = 1; i <= m; i++) path.push_back({sy ^ 3, i});
        for (int i = m; i >= tx; i--) path.push_back({sy, i});
      } else {
        for (int i = sx; i >= 1; i--) path.push_back({sy, i});
        for (int i = 1; i <= sx + 1; i++) path.push_back({ty, i});
        for (int i = sx + 1; i <= m; i++) path.push_back({sy, i});
        for (int i = m; i >= tx; i--) path.push_back({ty, i});
      }

      vector<vector<bool>> used(n + 1, vector<bool>(m + 1));
      for (auto [y, x] : path) used[y][x] = true;

      for (auto it = next(path.begin()); it != path.end(); ++it) {
        auto [y1, x1] = *prev(it);
        auto [y2, x2] = *it;
        if (y1 != y2) continue;

        int ny = y1 ^ 3;
        if (used[ny][x1] || used[ny][x2]) continue;
        used[ny][x1] = used[ny][x2] = true;
        path.insert(it, {make_pair(ny, x1), make_pair(ny, x2)});
      }
    }
    return path;
  }

  if (m <= 5) {
    auto Id = [&](int y, int x) {
      return (y - 1) * m + (x - 1);
    };

    auto YX = [&](int id) -> pair<int, int> {
      int y = id / m + 1;
      int x = id % m + 1;
      return {y, x};
    };

    auto In = [&](int y, int x) {
      return 1 <= y && y <= n && 1 <= x && x <= m;
    };

    vector<vector<int>> g(n * m);
    for (int y = 1; y <= n; y++) {
      for (int x = 1; x <= m; x++) {
        int u = Id(y, x);
        for (auto [dy, dx] : kDelta) {
          int yy = y + dy, xx = x + dx;
          if (In(yy, xx)) g[u].push_back(Id(yy, xx));
        }
      }
    }

    int st = Id(sy, sx), en = Id(ty, tx);
    int ub = CalcUpperBound(n, m, sy, sx, ty, tx);
    vector<bool> used(n * m);
    vector<pair<int, int>> memo(ub);

    [&](this auto&& self, int cur, int idx) -> bool {
      used[cur] = true;
      memo[idx] = YX(cur);

      if (cur == en) {
        used[cur] = false;
        if (idx + 1 != ub) return false;

        bool ok[4] = {};
        for (int i = 1; i < ub; i++) {
          auto [y1, x1] = memo[i - 1];
          auto [y2, x2] = memo[i];
          if (y1 == n && y2 == n) ok[0] = true;
          if (y1 == 1 && y2 == 1) ok[1] = true;
          if (x1 == m && x2 == m) ok[2] = true;
          if (x1 == 1 && x2 == 1) ok[3] = true;
        }
        return ok[0] && ok[1] && ok[2] && ok[3];
      }

      for (auto nxt : g[cur]) {
        if (used[nxt]) continue;
        if (self(nxt, idx + 1)) return true;
      }

      used[cur] = false;
      return false;
    }(st, 0);

    path.insert(path.begin(), memo.begin(), memo.end());
    return path;
  }

  if (TryStrip(n, m, sy, sx, ty, tx, path)) return path;
  if (TrySplit(n, m, sy, sx, ty, tx, path)) return path;

  assert(0);
  return path;
}

list<pair<int, int>> BuildLongestPath(int n, int m, int sy, int sx, int ty, int tx) {
  bool rot = false, yflip = false, xflip = false;
  if (n > m) swap(n, m), swap(sy, sx), swap(ty, tx), rot = true;
  if (sy > ty) sy = n - sy + 1, ty = n - ty + 1, yflip = true;
  if (sx > tx) sx = m - sx + 1, tx = m - tx + 1, xflip = true;

  auto path = BuildLongestPathInternal(n, m, sy, sx, ty, tx);

  auto ToGlobal = [&](int y, int x) -> pair<int, int> {
    if (xflip) x = m - x + 1;
    if (yflip) y = n - y + 1;
    if (rot) swap(y, x);
    return {y, x};
  };

  for (auto& [y, x] : path) tie(y, x) = ToGlobal(y, x);
  return path;
}

struct Seg {
  Seg(int t, int l) : type(t), len(l) {}

  int type, len;
};

list<Seg> Transform(const list<pair<int, int>>& path) {
  vector<int> rpath;
  rpath.reserve(path.size());
  for (auto it = next(path.begin()); it != path.end(); ++it) {
    auto [y1, x1] = *prev(it);
    auto [y2, x2] = *it;
    int dy = y2 - y1, dx = x2 - x1;

    int type;
    if (dy == 1) {
      type = 0;
    } else if (dy == -1) {
      type = 1;
    } else if (dx == 1) {
      type = 2;
    } else if (dx == -1) {
      type = 3;
    }
    rpath.push_back(type);
  }

  list<Seg> out;
  int idx = 0, nr = rpath.size();
  while (idx < nr) {
    int cur = rpath[idx], nxt = idx;
    while (nxt < nr && rpath[nxt] == cur) ++nxt;
    out.emplace_back(cur, nxt - idx);
    idx = nxt;
  }
  return out;
}

bool FindPath(int n, int m, int k, int sy, int sx, int ty, int tx, string& out) {
  int lb = abs(sy - ty) + abs(sx - tx) + 1;
  if (((lb + k) & 1) || k < lb) return false;

  int ub = CalcUpperBound(n, m, sy, sx, ty, tx);
  if (ub < k) return false;

  auto path = BuildLongestPath(n, m, sy, sx, ty, tx);
  assert(ub == path.size());

  auto rpath = Transform(path);

  auto IsCave = [&](list<Seg>::iterator it) {
    if (it == rpath.begin() || next(it) == rpath.end()) return false;
    auto lit = prev(it), rit = next(it);
    if ((lit->type ^ rit->type) != 1) return false;

    int len = min<int>(lit->len, rit->len);
    if (lit->len == len && lit != rpath.begin() && prev(lit)->type != it->type) return false;
    if (rit->len == len && next(rit) != rpath.end() && next(rit)->type != it->type) return false;
    return true;
  };

  auto Merge = [&](list<Seg>::iterator it) {
    if (it != rpath.begin()) {
      auto jt = prev(it);
      if (jt->type == it->type) {
        it->len += jt->len;
        rpath.erase(jt);
      }
    }
    if (next(it) != rpath.end()) {
      auto jt = next(it);
      if (jt->type == it->type) {
        it->len += jt->len;
        rpath.erase(jt);
      }
    }
  };

  auto Shrink = [&](int limit) {
    auto mit = rpath.begin();
    int md = INT_MAX, mc = 0;
    for (auto it = rpath.begin(); it != rpath.end(); ++it) {
      if (!IsCave(it)) continue;

      auto lit = prev(it), rit = next(it);

      int dist = it->len;
      int cut = min<int>(lit->len, rit->len);
      if (md > dist || (md == dist && mc < cut)) mit = it, md = dist, mc = cut;
    }

    auto lit = prev(mit), rit = next(mit);
    int cut = min<int>({limit, lit->len, rit->len});
    if ((lit->len -= cut) == 0) rpath.erase(lit), Merge(mit);
    if ((rit->len -= cut) == 0) rpath.erase(rit), Merge(mit);
    return cut;
  };

  int rem = (ub - k) >> 1;
  while (rem > 0) rem -= Shrink(rem);

  out.clear();
  for (auto e : rpath) {
    if (e.type == 0) {
      out.append(e.len, 'U');
    } else if (e.type == 1) {
      out.append(e.len, 'D');
    } else if (e.type == 2) {
      out.append(e.len, 'R');
    } else if (e.type == 3) {
      out.append(e.len, 'L');
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
    int n, m, sy, sx, ty, tx;
    cin >> n >> m >> sx >> sy >> tx >> ty;
    int ub = CalcUpperBound(n, m, sy, sx, ty, tx);
    if (FindPath(n, m, ub, sy, sx, ty, tx, path)) {
      cout << path << "\n";
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}
