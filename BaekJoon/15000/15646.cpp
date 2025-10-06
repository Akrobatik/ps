// Title : 농부 후안은 바리스타입니다
// Link  : https://www.acmicpc.net/problem/15646 
// Time  : 352 ms
// Memory: 185368 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> m >> n >> q;

  vector<vector<int64_t>> fwt(n + 2, vector<int64_t>(m + 2));

  auto UpdatePt = [&](int y, int x, int64_t v) {
    for (int i = y; i <= n; i += (i & -i)) {
      for (int j = x; j <= m; j += (j & -j)) {
        fwt[i][j] += v;
      }
    }
  };

  auto UpdateRc = [&](int y1, int x1, int y2, int x2, int64_t v) {
    UpdatePt(y1, x1, v);
    UpdatePt(y1, x2 + 1, -v);
    UpdatePt(y2 + 1, x1, -v);
    UpdatePt(y2 + 1, x2 + 1, v);
  };

  auto Calc = [&](int y, int x) -> int64_t {
    int64_t res = 0;
    for (int i = y; i > 0; i -= (i & -i)) {
      for (int j = x; j > 0; j -= (j & -j)) {
        res += fwt[i][j];
      }
    }
    return res;
  };

  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int x1, y1, x2, y2, d;
      cin >> x1 >> y1 >> x2 >> y2 >> d;
      UpdateRc(y1, x1, y2, x2, d);
    } else {
      int x, y;
      cin >> x >> y;
      cout << Calc(y, x) << "\n";
    }
  }

  return 0;
}