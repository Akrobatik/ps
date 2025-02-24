#include <bits/stdc++.h>

using namespace std;

struct Point {
  constexpr auto operator<=>(const Point& rhs) const {
    return x != rhs.x ? x <=> rhs.x : y <=> rhs.y;
  }

  constexpr bool operator==(const Point& rhs) const {
    return x == rhs.x && y == rhs.y;
  }

  int64_t x, y;
};

int CCW(const Point& a, const Point& b, const Point& c) {
  int64_t cp = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
  return (cp > 0) - (cp < 0);
}

bool IsIntersect(Point& a, Point& b, Point& c, Point& d) {
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

void PrintIntersection(Point& a, Point& b, Point& c, Point& d) {
  double dx1 = (double)(b.x - a.x), dy1 = (double)(b.y - a.y);
  double dx2 = (double)(d.x - c.x), dy2 = (double)(d.y - c.y);
  double dnom = dy1 * dx2 - dy2 * dx1;
  if (abs(dnom) < DBL_EPSILON) {
    if (b == c && a <= c) {
      cout << b.x << " " << b.y;
    } else if (a == d && c <= a) {
      cout << a.x << " " << a.y;
    }
  } else {
    double x = ((a.x * b.y - a.y * b.x) * dx2 - (c.x * d.y - c.y * d.x) * dx1) / dnom;
    double y = ((a.x * b.y - a.y * b.x) * dy2 - (c.x * d.y - c.y * d.x) * dy1) / dnom;
    cout.precision(9);
    cout << fixed << x << " " << y;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Point a, b, c, d;
  cin >> a.x >> a.y >> b.x >> b.y  //
      >> c.x >> c.y >> d.x >> d.y;

  if (IsIntersect(a, b, c, d)) {
    cout << "1\n";
    PrintIntersection(a, b, c, d);
  } else {
    cout << "0";
  }

  return 0;
}
