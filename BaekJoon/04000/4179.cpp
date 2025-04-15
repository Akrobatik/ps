// Title : 불!
// Link  : https://www.acmicpc.net/problem/4179 
// Time  : 28 ms
// Memory: 4108 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char board[1000][1000];
bool visited[1000][1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  queue<pair<int, int>> jq;
  queue<pair<int, int>> fq;

  int r, c;
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'J') {
        board[i][j] = '.';
        visited[i][j] = true;
        jq.push({i, j});
      } else if (board[i][j] == 'F') {
        fq.push({i, j});
      }
    }
  }

  for (int i = 1; !jq.empty(); i++) {
    int nf = fq.size();
    while (nf--) {
      auto [y, x] = fq.front();
      fq.pop();

      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy && yy < r && 0 <= xx && xx < c && board[yy][xx] == '.') {
          board[yy][xx] = 'F';
          fq.push({yy, xx});
        }
      }
    }

    int nj = jq.size();
    while (nj--) {
      auto [y, x] = jq.front();
      jq.pop();

      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy && yy < r && 0 <= xx && xx < c) {
          if (board[yy][xx] == '.' && !visited[yy][xx]) {
            visited[yy][xx] = true;
            jq.push({yy, xx});
          }
        } else {
          cout << i;
          return 0;
        }
      }
    }
  }
  cout << "IMPOSSIBLE";

  return 0;
}
