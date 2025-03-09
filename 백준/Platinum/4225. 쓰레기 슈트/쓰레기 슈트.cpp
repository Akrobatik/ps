#include <bits/stdc++.h>

using namespace std;

int CCW(int64_t ay, int64_t ax, int64_t by, int64_t bx) {
  int64_t cp = ax * by - ay * bx;
  return (cp > 0) - (cp < 0);
}

int64_t CrossProduct(int64_t ay, int64_t ax, int64_t by, int64_t bx, int64_t cy, int64_t cx) {
  return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(2);

  vector<pair<int64_t, int64_t>> coords;

  int n;
  int t = 0;
  while (cin >> n && n) {
    coords.resize(n);
    int miny = INT_MAX, minx;
    for (auto& [y, x] : coords) {
      cin >> y >> x;
      if (miny > y) miny = y, minx = x;
    }
    for (auto& [y, x] : coords) {
      y -= miny;
      x -= minx;
    }

    sort(coords.begin(), coords.end(), [](const pair<int64_t, int64_t>& lhs, const pair<int64_t, int64_t>& rhs) {
      auto [ay, ax] = lhs;
      auto [by, bx] = rhs;
      int ccw = CCW(ay, ax, by, bx);
      return ccw ? ccw > 0 : ay + abs(ax) < by + abs(bx);
    });

    vector<pair<int, int>> convex;
    convex.reserve(n);
    for (int i = 0; i < n; i++) {
      auto [cy, cx] = coords[i];
      while (convex.size() >= 2) {
        auto [ay, ax] = convex.back();
        convex.pop_back();
        auto [by, bx] = convex.back();
        if (CrossProduct(ay, ax, by, bx, cy, cx) < 0ll) {
          convex.push_back({ay, ax});
          break;
        }
      }
      convex.push_back({cy, cx});
    }

    double ans = DBL_MAX;
    for (int i = 0; i < convex.size(); i++) {
      auto [ay, ax] = convex[i];
      auto [by, bx] = convex[(i + 1) % convex.size()];
      int64_t cur = 0;
      for (auto [cy, cx] : convex) {
        cur = max<int64_t>(cur, abs(CrossProduct(ay, ax, by, bx, cy, cx)));
      }
      auto dy = ay - by, dx = ax - bx;
      ans = min<double>(ans, (double)cur / sqrt((double)(dy * dy + dx * dx)));
    }
    cout << "Case " << ++t << ": " << fixed << ceil(ans * 100.0) / 100.0 << "\n";
  }

  return 0;
}
