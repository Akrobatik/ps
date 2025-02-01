#include <bits/stdc++.h>

using namespace std;

struct Point {
  constexpr auto operator<=>(const Point& rhs) const {
    return x != rhs.x ? x <=> rhs.x : y <=> rhs.y;
  }

  int x, y;
};

struct Line {
  Point p1, p2;
};

int CCW(const Point& a, const Point& b, const Point& c) {
  int64_t cp = (int64_t)(b.x - a.x) * (int64_t)(c.y - a.y) - (int64_t)(b.y - a.y) * (int64_t)(c.x - a.x);
  return (cp > 0) - (cp < 0);
}

bool IsIntersect(const Line& l1, const Line& l2) {
  auto [a, b] = l1;
  auto [c, d] = l2;

  int abc = CCW(a, b, c);
  int abd = CCW(a, b, d);
  int cda = CCW(c, d, a);
  int cdb = CCW(c, d, b);

  if (abc == 0 && abd == 0) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return c <= b && a <= d;
  }
  return abc * abd <= 0 && cda * cdb <= 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Line l1, l2;
  cin >> l1.p1.x >> l1.p1.y >> l1.p2.x >> l1.p2.y  //
      >> l2.p1.x >> l2.p1.y >> l2.p2.x >> l2.p2.y;

  cout << IsIntersect(l1, l2);

  return 0;
}
