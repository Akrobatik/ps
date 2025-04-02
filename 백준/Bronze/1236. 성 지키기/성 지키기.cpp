#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<char>> board(n, vector<char>(m));
  for (auto& vec : board) {
    for (auto& c : vec) cin >> c;
  }

  vector<bool> r(n), c(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 'X') {
        r[i] = c[j] = true;
      }
    }
  }

  int rr = 0, cc = 0;
  for (auto e : r) rr += (e == false);
  for (auto e : c) cc += (e == false);
  cout << max<int>(rr, cc);

  return 0;
}
