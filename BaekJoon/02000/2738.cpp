// Title : 행렬 덧셈
// Link  : https://www.acmicpc.net/problem/2738 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int board[100][100] = {};

  int n, m;
  cin >> n >> m;

  for (int k = 0; k < 2; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        board[i][j] += x;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
