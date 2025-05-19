// Title : 인경호 확장판
// Link  : https://www.acmicpc.net/problem/33932 
// Time  : 0 ms
// Memory: 2168 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, r;
  cin >> n >> r;
  vector<pair<int, int>> coords(n);
  for (auto& [y, x] : coords) cin >> x >> y;

  vector<int> arr(n);
  iota(arr.begin(), arr.end(), 0);

  auto Calc = [&](int i) {
    auto [ly, lx] = coords[(i + n - 1) % n];
    auto [ry, rx] = coords[(i + 1) % n];

    int64_t dy = ly - ry, dx = lx - rx;
    return dy * dy + dx * dx;
  };

  int idx = *min_element(arr.begin(), arr.end(), [&](int lhs, int rhs) {
    int64_t l = Calc(lhs), r = Calc(rhs);
    return l > r || (l == r && lhs < rhs);
  });

  auto [ly, lx] = coords[(idx + n - 1) % n];
  auto [my, mx] = coords[idx];
  auto [ry, rx] = coords[(idx + 1) % n];

  long double dy = lx - rx, dx = ry - ly;
  long double dlen = hypot(dy, dx);
  dy *= (long double)r / dlen, dx *= (long double)r / dlen;

  long double y1 = (long double)my + dy, x1 = (long double)mx + dx;
  long double y2 = (long double)my - dy, x2 = (long double)mx - dx;

  auto GetArea = [](long double y1, long double x1, long double y2, long double x2, long double y3, long double x3) {
    return fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
  };

  if (GetArea(ly, lx, ry, rx, y1, x1) < GetArea(ly, lx, ry, rx, y2, x2)) y1 = y2, x1 = x2;

  cout << idx + 1 << "\n"
       << setprecision(9) << fixed << x1 << " " << y1;

  return 0;
}
