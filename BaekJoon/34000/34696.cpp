// Title : 아직은 어색해
// Link  : https://www.acmicpc.net/problem/34696 
// Time  : 64 ms
// Memory: 2972 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> xy(m);
  for (auto& [x, y] : xy) cin >> x >> y;

  int st;
  cin >> st, --st;
  vector<int> ans{st};
  vector<int8_t> mask(m);
  mask[st] = 1;

  vector<int64_t> memo(m);
  {
    auto [x, y] = xy[st];
    for (int i = 0; i < m; i++) {
      if (mask[i]) continue;
      auto [xx, yy] = xy[i];
      int64_t dx = x - xx, dy = y - yy;
      memo[i] = dx * dx + dy * dy;
    }
  }

  for (int i = 1; i < n; i++) {
    int64_t maxx = -1, mi;
    for (int j = 0; j < m; j++) {
      if (mask[j]) continue;
      int64_t cur = memo[j];
      if (maxx < cur) maxx = cur, mi = j;
    }
    auto [x, y] = xy[mi];
    for (int j = 0; j < m; j++) {
      if (mask[j]) continue;
      auto [xx, yy] = xy[j];
      int64_t dx = x - xx, dy = y - yy;
      memo[j] = min<int64_t>(memo[j], dx * dx + dy * dy);
    }
    ans.push_back(mi);
    mask[mi] = 1;
  }

  for (auto e : ans) cout << e + 1 << "\n";

  return 0;
}