// Title : Obraz
// Link  : https://www.acmicpc.net/problem/8245 
// Time  : 28 ms
// Memory: 3088 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<char>> board(n, vector<char>(m));
  for (auto& vec : board) {
    for (auto& e : vec) cin >> e;
  }

  for (int i = 0; i < m; i++) {
    for (int j = n - 1; j >= 0; j--) {
      cout << board[j][i];
    }
    cout << "\n";
  }

  return 0;
}
