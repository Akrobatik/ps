// Title : 횃불이의 모험
// Link  : https://www.acmicpc.net/problem/34557 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

constexpr char kCmd[] = "WASD";

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int cy, cx;
  vector<vector<int8_t>> mat(n, vector<int8_t>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      mat[i][j] = (x == 1 ? 1 : 0);
      if (x == 2) cy = i, cx = j;
    }
  }

  int type[4];
  for (int i = 0; i < 4; i++) {
    string s;
    cin >> s;
    type[i] = (s[0] == 'D' ? 0 : (s[0] == 'S' ? 1 : 2));
  }

  string cmd;
  cin >> cmd;

  auto Match = [&](int p, int i) {
    return (0 <= p && p < m && cmd[p] == kCmd[i]);
  };

  auto Process = [&](int p) {
    for (int i = 0; i < 4; i++) {
      bool ok = false;
      if (type[i] == 0) {
        ok = !Match(p - 1, i) && Match(p, i);
      } else if (type[i] == 1) {
        ok = Match(p - 1, i) && Match(p, i);
      } else {
        ok = Match(p - 1, i) && !Match(p, i);
      }

      if (ok) {
        auto [dy, dx] = kDelta[i];
        int y = cy + dy, x = cx + dx;
        if (0 <= y && y < n && 0 <= x && x < n && !mat[y][x]) {
          cy = y, cx = x;
        }
      }
    }
  };

  for (int i = 0; i < m; i++) Process(i);

  cout << cy + 1 << " " << cx + 1;

  return 0;
}