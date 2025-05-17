// Title : 점 분리
// Link  : https://www.acmicpc.net/problem/3878 
// Time  : 8 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

struct GrahamScan {
  void Init(span<pair<int, int>> coords) {
    auto [miny, minx] = *min_element(coords.begin(), coords.end());

    for (auto& [y, x] : coords) y -= miny, x -= minx;
    sort(coords.begin(), coords.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
      auto [ay, ax] = lhs;
      auto [by, bx] = rhs;
      int ccw = CCW(ay, ax, by, bx);
      return ccw ? ccw > 0 : ay + abs(ax) < by + abs(bx);
    });
    for (auto& [y, x] : coords) y += miny, x += minx;

    vertices.clear(), vertices.reserve(coords.size());
    for (auto c : coords) {
      auto rit = vertices.rbegin();
      while (vertices.size() >= 2 && CP(rit[0], rit[1], c) >= 0) vertices.pop_back(), ++rit;
      vertices.push_back(c);
    }
  }

  static int CCW(int64_t ay, int64_t ax, int64_t by, int64_t bx) {
    int64_t cp = ax * by - ay * bx;
    return (cp > 0) - (cp < 0);
  }

  static int CCW(int64_t ay, int64_t ax, int64_t by, int64_t bx, int64_t cy, int64_t cx) {
    int64_t cp = CP(ay, ax, by, bx, cy, cx);
    return (cp > 0) - (cp < 0);
  }

  static int64_t CP(int64_t ay, int64_t ax, int64_t by, int64_t bx, int64_t cy, int64_t cx) {
    return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
  }

  static int64_t CP(const pair<int, int>& a, const pair<int, int>& b, const pair<int, int>& c) {
    return CP(a.first, a.second, b.first, b.second, c.first, c.second);
  }

  vector<pair<int, int>> vertices;
};

int64_t CP(int64_t ay, int64_t ax, int64_t by, int64_t bx, int64_t cy, int64_t cx) {
  return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
}

int64_t CP(const pair<int, int>& a, const pair<int, int>& b, const pair<int, int>& c) {
  auto [ay, ax] = a;
  auto [by, bx] = b;
  auto [cy, cx] = c;
  return CP(ay, ax, by, bx, cy, cx);
}

int CCW(const pair<int, int>& a, const pair<int, int>& b, const pair<int, int>& c) {
  auto [ay, ax] = a;
  auto [by, bx] = b;
  auto [cy, cx] = c;
  int64_t cp = CP(ay, ax, by, bx, cy, cx);
  return (cp > 0) - (cp < 0);
}

bool PointInPoly(const pair<int, int>& pt, const vector<pair<int, int>>& poly) {
  int n = poly.size();
  if (n < 3) return false;
  for (int i = 0; i < n; i++) {
    if (CP(poly[i], poly[(i + 1) % n], pt) < 0) return false;
  }
  return true;
}

bool PointOnSegment(const pair<int, int>& pt, const pair<int, int>& a, const pair<int, int>& b) {
  if (CP(a, b, pt) != 0) return false;
  auto [ay, ax] = a;
  auto [by, bx] = b;
  auto [py, px] = pt;
  int miny = min<int>(ay, by), maxy = ay ^ by ^ miny;
  int minx = min<int>(ax, bx), maxx = ax ^ bx ^ minx;
  return miny <= py && py <= maxy && minx <= px && px <= maxx;
}

bool IntersectLine(const pair<int, int>& a1, const pair<int, int>& a2, const pair<int, int>& b1, const pair<int, int>& b2) {
  int o1 = CCW(a1, a2, b1);
  int o2 = CCW(a1, a2, b2);
  int o3 = CCW(b1, b2, a1);
  int o4 = CCW(b1, b2, a2);

  if (o1 == 0 && o2 == 0) {
    pair<int, int> mina = a1, maxa = a2;
    pair<int, int> minb = b1, maxb = b2;
    if (mina > maxa) swap(mina, maxa);
    if (minb > maxb) swap(minb, maxb);
    return minb <= maxa && mina <= maxb;
  }
  return o1 * o2 <= 0 && o3 * o4 <= 0;
}

bool IntersectPoly(const vector<pair<int, int>>& p1, const vector<pair<int, int>>& p2) {
  for (int i = 0; i < p1.size(); i++) {
    if (PointInPoly(p1[i], p2)) return true;
  }
  for (int i = 0; i < p2.size(); i++) {
    if (PointInPoly(p2[i], p1)) return true;
  }
  return false;
}

GrahamScan asol, bsol;
vector<pair<int, int>> arr, brr;

void Solve() {
  int n, m;
  cin >> n >> m;
  arr.resize(n), brr.resize(m);
  for (auto& [y, x] : arr) cin >> x >> y;
  for (auto& [y, x] : brr) cin >> x >> y;

  asol.Init(arr), bsol.Init(brr);
  auto& axr = asol.vertices;
  auto& bxr = bsol.vertices;
  if (axr.size() > bxr.size()) swap(axr, bxr);

  if (axr.size() == 1 && bxr.size() == 1) {
    cout << "YES\n";
  } else if (axr.size() == 1) {
    if (bxr.size() == 2) {
      cout << (PointOnSegment(axr[0], bxr[0], bxr[1]) ? "NO\n" : "YES\n");
    } else {
      cout << (PointInPoly(axr[0], bxr) ? "NO\n" : "YES\n");
    }
  } else if (axr.size() == 2 && bxr.size() == 2) {
    cout << (IntersectLine(axr[0], axr[1], bxr[0], bxr[1]) ? "NO\n" : "YES\n");
  } else {
    cout << (IntersectPoly(axr, bxr) ? "NO\n" : "YES\n");
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) Solve();

  return 0;
}