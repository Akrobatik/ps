#include <bits/stdc++.h>

using namespace std;

int64_t Wait(int64_t cur, int64_t t, int64_t s) {
  if (cur < s) return s - cur;
  auto dv = div(cur - s, t);
  return (dv.quot & 1) * (t - dv.rem);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<tuple<int64_t, int64_t, int64_t>> blinkers(k);
  for (int i = 0; i < k; i++) {
    int64_t x, t, s;
    cin >> x >> t >> s;
    blinkers[i] = {x, t, s};
  }
  sort(blinkers.begin(), blinkers.end());

  int64_t sec = 0;
  int64_t pos = 0;
  for (auto [x, t, s] : blinkers) {
    sec += x - pos;
    sec += Wait(sec, t, s);
    pos = x;
  }

  cout << sec + (n - pos);

  return 0;
}
