// Title : 단순 다각형
// Link  : https://www.acmicpc.net/problem/3679
// Time  : 8 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int64_t miny, minx;

int CCW(int64_t ay, int64_t ax, int64_t by, int64_t bx) {
  int64_t cp = (ax - minx) * (by - miny) - (ay - miny) * (bx - minx);
  return (cp > 0) - (cp < 0);
}

int64_t Distance(int64_t y, int64_t x) {
  return (y - miny) * (y - miny) + (x - minx) * (x - minx);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    miny = minx = INT64_MAX;

    int n;
    cin >> n;
    vector<tup> coords(n);
    for (int i = 0; i < n; i++) {
      auto& [y, x, idx] = coords[i];
      cin >> y >> x;
      idx = i;
      if (miny > y) miny = y, minx = x;
    }

    sort(coords.begin(), coords.end(), [](const tup& lhs, const tup& rhs) {
      auto [ay, ax, ai] = lhs;
      auto [by, bx, bi] = rhs;
      int ccw = CCW(ay, ax, by, bx);
      return ccw ? ccw > 0 : Distance(ay, ax) < Distance(by, bx);
    });

    int ri = n - 2;
    auto [by, bx, _] = coords.back();
    while (ri >= 0 && CCW(by, bx, get<0>(coords[ri]), get<1>(coords[ri])) == 0) --ri;
    reverse(coords.begin() + ri + 1, coords.end());

    cout << get<2>(coords[0]);
    for (int i = 1; i < n; i++) {
      cout << " " << get<2>(coords[i]);
    }
    cout << "\n";
  }

  return 0;
}
