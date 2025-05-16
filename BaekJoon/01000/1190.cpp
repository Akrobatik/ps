// Title : 골 세레모니
// Link  : https://www.acmicpc.net/problem/1190 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

constexpr double kEpsilon = 1e-9;

using Point = pair<int, int>;
using Line = pair<Point, Point>;

int64_t CP(const Point& a, const Point& b, const Point& c) {
  return (int64_t)(b.first - a.first) * (c.second - a.second) - (int64_t)(b.second - a.second) * (c.first - a.first);
}

int CCW(const Point& a, const Point& b, const Point& c) {
  int64_t cp = CP(a, b, c);
  return (cp > 0) - (cp < 0);
}

bool IsIntersect(const Line& l1, const Line& l2) {
  auto [a, b] = l1;
  auto [c, d] = l2;

  int abc = CCW(a, b, c);
  int abd = CCW(a, b, d);
  int cda = CCW(c, d, a);
  int cdb = CCW(c, d, b);
  return abc * abd < 0 && cda * cdb < 0;
}

bool IsIntersect(const Line& line, const vector<vector<Point>>& polys) {
  for (auto& poly : polys) {
    int nv = poly.size();
    for (int i = 0; i < nv; i++) {
      int j = (i + 1) % nv;
      Line l = {poly[i], poly[j]};
      if (IsIntersect(line, l)) return true;
    }
  }

  auto F = [&](const Point& pt) {
    auto [st, en] = line;
    int64_t cp = CP(st, en, pt);
    if (cp == 0) {
      int vx = en.first - st.first, vy = en.second - st.second;
      int wx = pt.first - st.first, wy = pt.second - st.second;
      int64_t dot = (int64_t)vx * wx + (int64_t)vy * wy;
      if (dot >= 0) return 0;
      return -1;
    }
    return (cp > 0 ? 1 : -1);
  };

  for (auto& poly : polys) {
    int nv = poly.size();
    for (int i = 0; i < nv; i++) {
      int j = (i + 1) % nv, k = (i + 2) % nv, l = (i + 3) % nv;
      if (F(poly[j]) == 0) {
        if (F(poly[i]) * F(poly[k]) == -1) return true;
        if (nv != 3 && F(poly[k]) == 0 && F(poly[i]) * F(poly[l]) == -1) return true;
      }
    }
  }

  return false;
}

pair<int, int> Expand(int sx, int sy, int tx, int ty, int n, int m) {
  double dx = tx - sx, dy = ty - sy;
  double bt = numeric_limits<double>::infinity();

  auto Update = [&](double t) {
    if (t <= 0 || t >= bt) return;
    double x = sx + dx * t;
    double y = sy + dy * t;
    if (-kEpsilon < x && x < n + kEpsilon && -kEpsilon < y && y < m + kEpsilon) bt = t;
  };

  if (sx != tx) {
    Update((double)(0 - sx) / dx);
    Update((double)(n - sx) / dx);
  }
  if (sy != ty) {
    Update((double)(0 - sy) / dy);
    Update((double)(m - sy) / dy);
  }

  int t = (int)(bt + 1.0);
  return {sx + (tx - sx) * t, sy + (ty - sy) * t};
}

pair<double, double> Find(int sx, int sy, int tx, int ty, int n, int m) {
  double dx = tx - sx, dy = ty - sy;
  double bt = numeric_limits<double>::infinity();

  auto Update = [&](double t) {
    if (t <= 0 || t >= bt) return;
    double x = sx + dx * t;
    double y = sy + dy * t;
    if (-kEpsilon < x && x < n + kEpsilon && -kEpsilon < y && y < m + kEpsilon) bt = t;
  };

  if (sx != tx) {
    Update((double)(0 - sx) / dx);
    Update((double)(n - sx) / dx);
  }
  if (sy != ty) {
    Update((double)(0 - sy) / dy);
    Update((double)(m - sy) / dy);
  }

  return {sx + dx * bt, sy + dy * bt};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, sx, sy, g;
  cin >> n >> m >> sx >> sy >> g;
  Point st{sx, sy};

  vector<Point> pts = {
      {0, 0}, {n, 0}, {n, m}, {0, m}};

  vector<vector<Point>> polys(g);
  for (auto& poly : polys) {
    int nv;
    cin >> nv;
    poly.resize(nv);
    for (auto& [x, y] : poly) cin >> x >> y;
    pts.insert(pts.end(), poly.begin(), poly.end());
  }

  vector<pair<int, int>> cands;
  cands.reserve(pts.size());
  for (auto [x, y] : pts) {
    if (x == sx && y == sy) continue;
    auto pt = Expand(sx, sy, x, y, n, m);
    if (!IsIntersect({st, pt}, polys)) cands.push_back({x, y});
  }

  if (cands.empty()) {
    cout << "GG";
    return 0;
  }

  double bd = -1.0, bx, by;
  for (auto& pt : cands) {
    auto [x, y] = Find(sx, sy, pt.first, pt.second, n, m);
    double dx = (double)sx - x, dy = (double)sy - y;
    double d = dx * dx + dy * dy;
    if (fabs(bd - d) < kEpsilon) {
      if (fabs(bx - x) < kEpsilon) {
        if (by > y) {
          bd = d, bx = x, by = y;
        }
      } else if (bx > x) {
        bd = d, bx = x, by = y;
      }
    } else if (bd < d) {
      bd = d, bx = x, by = y;
    }
  }

  if (bd < 0.0) {
    cout << "GG";
  } else {
    bx = min<double>(max<double>(bx, 0.0), n), by = min<double>(max<double>(by, 0.0), m);
    cout << setprecision(3) << fixed << bx << " " << by;
  }

  return 0;
}
