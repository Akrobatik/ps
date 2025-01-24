#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int64_t, int64_t>> dots;
  dots.reserve(n + 1);
  for (int i = 0; i < n; i++) {
    int64_t x, y;
    cin >> x >> y;
    dots.push_back({x, y});
  }
  dots.push_back(dots.front());

  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (double)(dots[i].first * dots[i + 1].second);
    sum -= (double)(dots[i].second * dots[i + 1].first);
  }

  cout << fixed << setprecision(1) << abs(sum * 0.5) << endl;

  return 0;
}
