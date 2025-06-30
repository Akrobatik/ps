// Title : 불
// Link  : https://www.acmicpc.net/problem/5427 
// Time  : 36 ms
// Memory: 4748 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> board;

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> m >> n;
    board.resize(n);
    for (auto& s : board) cin >> s;

    queue<pair<int, int>> fq, sq;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == '*') fq.push({i, j}), board[i][j] = '#';
        if (board[i][j] == '@') sq.push({i, j});
      }
    }

    int ans = -1;
    for (int i = 1; !sq.empty(); i++) {
      int nf = fq.size();
      while (nf--) {
        auto [y, x] = fq.front();
        fq.pop();

        for (auto [dy, dx] : kDelta) {
          int yy = y + dy, xx = x + dx;
          if (0 <= yy && yy < n && 0 <= xx && xx < m && board[yy][xx] != '#') {
            board[yy][xx] = '#';
            fq.push({yy, xx});
          }
        }
      }

      bool ok = false;

      int ns = sq.size();
      while (ns--) {
        auto [y, x] = sq.front();
        sq.pop();

        for (auto [dy, dx] : kDelta) {
          int yy = y + dy, xx = x + dx;
          if (0 <= yy && yy < n && 0 <= xx && xx < m) {
            if (board[yy][xx] == '.') {
              board[yy][xx] = '@';
              sq.push({yy, xx});
            }
          } else {
            ok = true;
          }
        }
      }

      if (!ok) continue;
      ans = i;
      break;
    }

    if (ans != -1) {
      cout << ans << "\n";
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }

  return 0;
}
