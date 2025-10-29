// Title : 드럼통 쌓기
// Link  : https://www.acmicpc.net/problem/2734 
// Time  : 0 ms
// Memory: 2036 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<pair<double, double>> arr, axr;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    arr.resize(n);
    for (auto& [x, y] : arr) {
      cin >> x, y = 1.0;
    }
    sort(arr.begin(), arr.end());

    while (arr.size() > 1) {
      axr.clear();
      for (int i = 1; i < arr.size(); i++) {
        auto [x1, y1] = arr[i - 1];
        auto [x2, y2] = arr[i];

        double dx = x2 - x1, dy = y2 - y1;
        double d = hypot(dx, dy);

        double ux = dx / d, uy = dy / d;
        double v = d * 0.5;
        double h = sqrt(4.0 - v * v);

        double px = x1 + v * ux, py = y1 + v * uy;

        if (h * ux > 0) {
          axr.push_back({px - h * uy, py + h * ux});
        } else {
          axr.push_back({px + h * uy, py - h * ux});
        }
      }
      swap(arr, axr);
    }

    auto [x, y] = arr[0];
    cout << setprecision(4) << fixed << x << " " << y << "\n";
  }

  return 0;
}