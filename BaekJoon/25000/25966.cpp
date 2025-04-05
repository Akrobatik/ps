// Title : 배찬우는 배열을 좋아해
// Link  : https://www.acmicpc.net/problem/25966
// Time  : 1488 ms
// Memory: 37404 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c, q;
  cin >> r >> c >> q;
  vector<vector<int>> m(r, vector<int>(c));
  vector<int> rows(r);
  iota(rows.begin(), rows.end(), 0);

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) cin >> m[i][j];
  }

  while (q--) {
    int t;
    cin >> t;
    if (t) {
      int i, j;
      cin >> i >> j;
      swap(rows[i], rows[j]);
    } else {
      int i, j, k;
      cin >> i >> j >> k;
      m[rows[i]][j] = k;
    }
  }

  for (int i = 0; i < r; i++) {
    int ii = rows[i];
    for (int j = 0; j < c; j++) cout << m[ii][j] << " ";
    cout << "\n";
  }

  return 0;
}
