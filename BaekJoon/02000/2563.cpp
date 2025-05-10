// Title : 색종이
// Link  : https://www.acmicpc.net/problem/2563 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool board[100][100] = {};

  int n;
  cin >> n;
  while (n--) {
    int y, x;
    cin >> y >> x;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        board[y + i][x + j] = true;
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      cnt += board[i][j];
    }
  }
  cout << cnt;

  return 0;
}
