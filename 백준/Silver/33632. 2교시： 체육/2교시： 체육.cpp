#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  double w, h, x, y;
  cin >> w >> h >> x >> y;
  double px, py, qx, qy;
  cin >> px >> py >> qx >> qy;

  double ans = 0.0;
  if (py < y) {
    double r = max<double>(0.0, min<double>(w, x + (qx - x) * y / (y - py)));
    double l = max<double>(0.0, min<double>(w, x + (px - x) * y / (y - py)));
    ans = (r - l) / w;
  }
  cout.precision(12);
  cout << fixed << ans;

  return 0;
}
