// Title : 지뢰 찾기
// Link  : https://www.acmicpc.net/problem/4396 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char board[10][10], cover[10][10];

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> cover[i][j];
      if (cover[i][j] == 'x' && board[i][j] == '*') ok = false;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (cover[i][j] == 'x' && board[i][j] == '.') {
        int cnt = 0;
        for (auto [dy, dx] : kDelta) {
          int y = i + dy, x = j + dx;
          if (0 <= y && y < n && 0 <= x && x < n && board[y][x] == '*') {
            ++cnt;
          }
        }
        cover[i][j] = '0' + cnt;
      }
      if (!ok && board[i][j] == '*') cover[i][j] = '*';
      cout << cover[i][j];
    }
    cout << "\n";
  }

  return 0;
}
