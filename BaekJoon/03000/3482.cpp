// Title : Labyrinth
// Link  : https://www.acmicpc.net/problem/3482 
// Time  : 60 ms
// Memory: 8072 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<string> board;
int ans;

int Traverse(int y, int x) {
  int maxx[2] = {};

  board[y][x] = '#';
  for (auto [dy, dx] : kDelta) {
    int yy = y + dy, xx = x + dx;
    if (board[yy][xx] != '.') continue;
    int cur = Traverse(yy, xx);
    if (maxx[0] <= cur) {
      maxx[1] = maxx[0];
      maxx[0] = cur;
    } else if (maxx[1] < cur) {
      maxx[1] = cur;
    }
  }
  ans = max<int>(ans, maxx[0] + maxx[1]);

  return maxx[0] + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> m >> n;
    board.resize(n);
    for (auto& s : board) cin >> s;

    int ry = -1, rx = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] != '.') continue;
        ry = i, rx = j;
        break;
      }
      if (ry != -1 && rx != -1) break;
    }

    ans = 0;
    if (ry != -1 && rx != -1) Traverse(ry, rx);

    cout << "Maximum rope length is " << ans << ".\n";
  }

  return 0;
}
