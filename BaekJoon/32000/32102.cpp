// Title : 삼색정리
// Link  : https://www.acmicpc.net/problem/32102 
// Time  : 552 ms
// Memory: 37288 KB

#include <bits/stdc++.h>

using namespace std;

constexpr const char* kType = "RGB";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int nm = n * m;

  vector<pair<int, int>> arr;
  arr.reserve(nm);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      arr.push_back({i, j});
    }
  }

  sort(arr.begin(), arr.end(), [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    auto [ly, lx] = lhs;
    auto [ry, rx] = rhs;

    int ls = ly + lx, rs = ry + rx;
    int lv = ls & 1, rv = rs & 1;
    if (lv != rv) return lv < rv;
    if (ls != rs) return ls < rs;
    return lx < rx;
  });

  pair<int, int> color[3];
  for (int i = 0; i < 3; i++) {
    int x;
    cin >> x;
    color[i] = {x, i};
  }
  sort(color, color + 3, greater<pair<int, int>>());
  swap(color[1], color[2]);

  int ub = (nm + 1) >> 1;
  if (color[0].first > ub) {
    cout << "NO";
    return 0;
  }

  vector<string> board(n, string(m, 'X'));

  for (int i = 0, j = 0; i < 3; i++) {
    auto [rem, type] = color[i];
    while (rem--) {
      auto [y, x] = arr[j++];
      board[y][x] = kType[type];
    }
  }

  cout << "YES\n";
  for (auto& s : board) cout << s << "\n";

  return 0;
}
