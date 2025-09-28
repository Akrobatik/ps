// Title : Polyominonal Puzzle
// Link  : https://www.acmicpc.net/problem/34511 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<string> board(n);
  for (auto& s : board) cin >> s;

  auto Check = [&](int y, int x) {
    if (!(0 <= y && y < n && 0 <= x && x < m)) return false;
    return board[y][x] == 'Y';
  };

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] != 'X') continue;
      for (auto [dy, dx] : kDelta) {
        cnt += Check(i + dy, j + dx);
      }
    }
  }
  cout << cnt;

  return 0;
}