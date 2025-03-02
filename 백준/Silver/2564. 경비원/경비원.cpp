#include <bits/stdc++.h>

using namespace std;

int r, c, xt, xd;
int Calc(int t, int d) {
  if (t == xt) return abs(d - xd);
  if (t == (xt ^ 1)) {
    if (t & 2) return c + min<int>(d + xd, (r << 1) - d - xd);
    return r + min<int>(d + xd, (c << 1) - d - xd);
  }
  if (t & 2) return ((t & 1) ? c - xd : xd) + ((xt & 1) ? r - d : d);
  return ((t & 1) ? r - xd : xd) + ((xt & 1) ? c - d : d);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> c >> r >> n;
  vector<pair<int, int>> vec(n);
  while (n--) cin >> vec[n].first >> vec[n].second;
  cin >> xt >> xd;
  --xt;
  int sum = 0;
  for (auto [t, d] : vec) {
    sum += Calc(t - 1, d);
  }
  cout << sum;

  return 0;
}
