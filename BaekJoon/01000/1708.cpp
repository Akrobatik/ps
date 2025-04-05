// Title : 볼록 껍질
// Link  : https://www.acmicpc.net/problem/1708
// Time  : 36 ms
// Memory: 4372 KB

#include <bits/stdc++.h>

using namespace std;

struct Point {
  constexpr auto operator<=>(const Point& rhs) const {
    return x != rhs.x ? x <=> rhs.x : y <=> rhs.y;
  }

  int64_t x, y;
};

int CCW(const Point& a, const Point& b, const Point& c) {
  int64_t cp = (int64_t)(b.x - a.x) * (int64_t)(c.y - a.y) - (int64_t)(b.y - a.y) * (int64_t)(c.x - a.x);
  return (cp > 0) - (cp < 0);
}

Point pts[100000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> pts[i].x >> pts[i].y;
  }
  sort(pts, pts + n, [](const Point& lhs, const Point& rhs) {
    return lhs.y != rhs.y ? lhs.y < rhs.y : lhs.x < rhs.x;
  });
  for (int i = 1; i < n; i++) {
    pts[i].x -= pts[0].x;
    pts[i].y -= pts[0].y;
  }
  pts[0] = {0, 0};
  sort(pts + 1, pts + n, [](const Point& lhs, const Point& rhs) {
    return lhs.x * rhs.y != lhs.y * rhs.x ? lhs.x * rhs.y < lhs.y * rhs.x : lhs.y + abs(lhs.x) < rhs.y + abs(rhs.x);
  });

  vector<Point*> vec;
  vec.reserve(n);
  for (int i = 0; i < n; i++) {
    while (vec.size() >= 2) {
      auto cand = vec.back();
      vec.pop_back();
      auto fixed = vec.back();
      if (CCW(*cand, *fixed, pts[i]) == 1) {
        vec.push_back(cand);
        break;
      }
    }
    vec.push_back(pts + i);
  }

  cout << vec.size();

  return 0;
}
