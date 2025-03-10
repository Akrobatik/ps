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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(2);

  GrahamScan scanner;
  vector<pair<int, int>> coords;

  int n;
  int t = 0;
  while (cin >> n && n) {
    coords.resize(n);
    for (auto& [y, x] : coords) {
      cin >> y >> x;
    }
    scanner.Init(coords);
    auto& convex = scanner.vertices;

    double ans = DBL_MAX;
    for (int i = 0; i < convex.size(); i++) {
      auto [ay, ax] = convex[i];
      auto [by, bx] = convex[(i + 1) % convex.size()];
      int64_t cur = 0;
      for (auto [cy, cx] : convex) {
        cur = max<int64_t>(cur, abs(GrahamScan::CP(ay, ax, by, bx, cy, cx)));
      }
      auto dy = ay - by, dx = ax - bx;
      ans = min<double>(ans, (double)cur / sqrt((double)(dy * dy + dx * dx)));
    }
    cout << "Case " << ++t << ": " << fixed << ceil(ans * 100.0) / 100.0 << "\n";
  }

  return 0;
}
