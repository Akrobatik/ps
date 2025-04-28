// Title : 로버트 후드
// Link  : https://www.acmicpc.net/problem/9240 
// Time  : 28 ms
// Memory: 3604 KB

#include <bits/stdc++.h>

using namespace std;

struct RotatingCalipers {
  tuple<int, int, int, int> Solve(span<pair<int, int>> coords) {
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
      while (vertices.size() >= 2 && CCW(rit[0], rit[1], c) != -1) vertices.pop_back(), ++rit;
      vertices.push_back(c);
    }

    int64_t maxx = 0;
    int n = vertices.size();
    pair<int, int> a{}, b{};
    for (int i = 0, j = 0; i < n; i++) {
      if (j + 1 < n) {
        auto yx = GetVector(vertices[i], vertices[i + 1]);
        while (j + 1 < n && CCW(yx, GetVector(vertices[j], vertices[j + 1])) != -1) {
          int64_t dist = GetDistance(vertices[i], vertices[j]);
          if (maxx < dist) maxx = dist, a = vertices[i], b = vertices[j];
          ++j;
        }
      }
      int64_t dist = GetDistance(vertices[i], vertices[j]);
      if (maxx < dist) maxx = dist, a = vertices[i], b = vertices[j];
    }
    return {a.first, a.second, b.first, b.second};
  }

  static int CCW(int64_t ay, int64_t ax, int64_t by, int64_t bx) {
    int64_t cp = ax * by - ay * bx;
    return (cp > 0) - (cp < 0);
  }

  static int CCW(int64_t ay, int64_t ax, int64_t by, int64_t bx, int64_t cy, int64_t cx) {
    int64_t cp = (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
    return (cp > 0) - (cp < 0);
  }

  static int CCW(const pair<int, int>& a, const pair<int, int>& b) {
    return CCW(a.first, a.second, b.first, b.second);
  }

  static int CCW(const pair<int, int>& a, const pair<int, int>& b, const pair<int, int>& c) {
    return CCW(a.first, a.second, b.first, b.second, c.first, c.second);
  }

  static pair<int, int> GetVector(const pair<int, int>& u, const pair<int, int>& v) {
    return {v.first - u.first, v.second - u.second};
  }

  static int64_t GetDistance(const pair<int, int>& u) {
    auto [dx, dy] = u;
    return (int64_t)dx * dx + (int64_t)dy * dy;
  }

  static int64_t GetDistance(const pair<int, int>& u, const pair<int, int>& v) {
    auto [dx, dy] = GetVector(u, v);
    return (int64_t)dx * dx + (int64_t)dy * dy;
  }

 private:
  vector<pair<int, int>> vertices;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  RotatingCalipers solver;

  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for (auto& [y, x] : arr) cin >> y >> x;

  auto [y1, x1, y2, x2] = solver.Solve(arr);
  int dy = y1 - y2, dx = x1 - x2;
  cout << setprecision(6) << fixed << sqrt((double)(dy * dy + dx * dx));

  return 0;
}
