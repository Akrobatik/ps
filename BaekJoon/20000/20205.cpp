// Title : 교수님 그림이 깨지는데요?
// Link  : https://www.acmicpc.net/problem/20205 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> board(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < n * m; i++) {
    for (int j = 0; j < n * m; j++) {
      cout << board[i / m][j / m] << " ";
    }
    cout << "\n";
  }

  return 0;
}