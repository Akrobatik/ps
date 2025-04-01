#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<double, double>> arr(n);
  for (auto& [x, y] : arr) cin >> x >> y;

  int m;
  cin >> m;
  while (m--) {
    int np;
    cin >> np;
    vector<int> prr(np);
    for (auto& e : prr) cin >> e;

    double ans = 0.0;
    for (int i = 1; i < np; i++) {
      auto [x1, y1] = arr[prr[i - 1]];
      auto [x2, y2] = arr[prr[i]];
      ans += hypot(x1 - x2, y1 - y2);
    }
    cout << (int64_t)round(ans) << "\n";
  }

  return 0;
}
