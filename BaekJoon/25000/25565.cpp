// Title : 딸기와 토마토
// Link  : https://www.acmicpc.net/problem/25565 
// Time  : 192 ms
// Memory: 2176 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  int maxx = k << 1;

  vector<pair<int, int>> coords;
  coords.reserve(maxx);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      if (x != 0) coords.push_back({i, j});
    }
  }
  sort(coords.begin(), coords.end());

  int dup = maxx - coords.size();
  cout << dup << "\n";
  if (dup != 0) {
    auto [sy, sx] = coords[0];
    bool oky = true, okx = true;
    for (int i = 1; i < coords.size(); i++) {
      auto [y, x] = coords[i];
      if (oky) oky = (y == sy);
      if (okx) okx = (x == sx);
    }

    if (oky || okx) {
      for (int i = k - dup; i < k; i++) {
        auto [y, x] = coords[i];
        cout << y << " " << x << "\n";
      }
    } else {
      int cnty[2001] = {}, cntx[2001] = {};
      int y, x;
      for (auto [yy, xx] : coords) {
        if (++cnty[yy] == 2) y = yy;
        if (++cntx[xx] == 2) x = xx;
      }
      cout << y << " " << x;
    }
  }

  return 0;
}
