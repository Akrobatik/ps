// Title : 내적
// Link  : https://www.acmicpc.net/problem/24894 
// Time  : 92 ms
// Memory: 4504 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> axr(n);
  for (auto& [x, y] : axr) cin >> x >> y;
  sort(axr.begin(), axr.end());

  vector<pair<int, int>> arr;

  auto Check = [&](int64_t aa, int64_t ab, int64_t ba, int64_t bb, int64_t ca, int64_t cb) {
    return (bb - cb) * (ca - aa) <= (ca - ba) * (ab - cb);
  };

  auto Push = [&](int64_t ca, int64_t cb) {
    while (arr.size() > 1) {
      auto [aa, ab] = arr[arr.size() - 2];
      auto [ba, bb] = arr.back();
      if (Check(aa, ab, ba, bb, ca, cb)) {
        arr.pop_back();
      } else {
        break;
      }
    }
    arr.push_back({ca, cb});
  };

  for (auto [x, y] : axr) Push(x, y);

  auto Calc = [&](int64_t ix, int64_t iy, int64_t jx, int64_t jy) {
    return ix * jx + iy * jy;
  };

  int m = arr.size();
  int64_t maxx = 0;
  for (auto [x, y] : axr) {
    int lo = 0, hi = m - 1;
    while (lo + 2 < hi) {
      int ml = (lo + lo + hi) / 3;
      int mr = (lo + hi + hi) / 3;
      auto [lx, ly] = arr[ml];
      auto [rx, ry] = arr[mr];
      if (Calc(x, y, lx, ly) < Calc(x, y, rx, ry)) {
        lo = ml;
      } else {
        hi = mr;
      }
    }

    for (int j = lo; j <= hi; j++) {
      auto [xx, yy] = arr[j];
      if (x == xx && y == yy) continue;
      int64_t cur = Calc(x, y, xx, yy);
      maxx = max<int64_t>(maxx, cur);
    }
  }
  cout << maxx;

  return 0;
}