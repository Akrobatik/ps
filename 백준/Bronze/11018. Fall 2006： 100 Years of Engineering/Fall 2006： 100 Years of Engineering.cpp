#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<tuple<double, double, double>> arr;

  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n;
    double w;
    cin >> n >> w;
    arr.resize(n);
    for (auto& [m, t, f] : arr) cin >> m >> t >> f, w += m;

    double h = 0, v = 0;
    for (auto [m, t, f] : arr) {
      double x = -9.81 + f / w;
      h += v * t + x * t * t / 2.0;
      v += x * t;
      w -= m;
    }

    cout << "Data Set " << i << ":\n"
         << setprecision(2) << fixed << round(h * 100.0) / 100.0 << "\n\n";
  }

  return 0;
}
