// Title : CSS IS AWESOME
// Link  : https://www.acmicpc.net/problem/34335 
// Time  : 152 ms
// Memory: 64820 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int w, h, n;
  cin >> w >> h >> n;

  vector<tup> arr(n);
  vector<int> xrr{0, w}, yrr{0, h};
  xrr.reserve((n << 1) + 2), yrr.reserve((n << 1) + 2);
  for (auto& [x1, y1, x2, y2] : arr) {
    cin >> x1 >> y1 >> x2 >> y2;
    xrr.push_back(x1), xrr.push_back(x2);
    yrr.push_back(y1), yrr.push_back(y2);
  }

  sort(xrr.begin(), xrr.end());
  xrr.erase(unique(xrr.begin(), xrr.end()), xrr.end());
  sort(yrr.begin(), yrr.end());
  yrr.erase(unique(yrr.begin(), yrr.end()), yrr.end());

  int rw = xrr.size(), rh = yrr.size();
  vector<vector<int>> memo(rh, vector<int>(rw));

  for (auto& [x1, y1, x2, y2] : arr) {
    x1 = lower_bound(xrr.begin(), xrr.end(), x1) - xrr.begin();
    x2 = lower_bound(xrr.begin(), xrr.end(), x2) - xrr.begin();
    y1 = lower_bound(yrr.begin(), yrr.end(), y1) - yrr.begin();
    y2 = lower_bound(yrr.begin(), yrr.end(), y2) - yrr.begin();

    ++memo[y1][x1];
    --memo[y1][x2];
    --memo[y2][x1];
    ++memo[y2][x2];
  }

  for (int i = 0; i < rh; i++) {
    for (int j = 0; j < rw; j++) {
      if (i) memo[i][j] += memo[i - 1][j];
      if (j) memo[i][j] += memo[i][j - 1];
      if (i && j) memo[i][j] -= memo[i - 1][j - 1];
    }
  }

  vector<int> axr(rw - 1);
  for (int i = 1; i < rw; i++) {
    axr[i - 1] = xrr[i] - xrr[i - 1];
  }

  int64_t maxx = 0;
  vector<int> cnt(rw - 1);
  vector<pair<int, int>> stk;
  for (int i = 0; i + 1 < rh; i++) {
    int d = yrr[i + 1] - yrr[i];
    for (int j = 0; j + 1 < rw; j++) {
      if (memo[i][j] == 0) {
        cnt[j] += d;
      } else {
        cnt[j] = 0;
      }
    }

    stk.clear();
    for (int j = 0; j + 1 < rw; j++) {
      int64_t cw = cnt[j], ch = axr[j];
      int64_t val = 0;
      while (!stk.empty() && stk.back().first > cw) {
        auto [ww, hh] = stk.back();
        stk.pop_back();
        val += hh;
        maxx = max<int64_t>(maxx, val * ww);
      }
      val += ch;

      if (!stk.empty() && stk.back().first == cw) {
        stk.back().second += val;
      } else {
        stk.push_back({cw, val});
      }
    }

    int64_t val = 0;
    while (!stk.empty()) {
      auto [ww, hh] = stk.back();
      stk.pop_back();
      val += hh;
      maxx = max<int64_t>(maxx, val * ww);
    }
  }
  cout << maxx;

  return 0;
}
