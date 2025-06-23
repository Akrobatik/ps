// Title : 별 찍기 - 10
// Link  : https://www.acmicpc.net/problem/2447 
// Time  : 68 ms
// Memory: 6836 KB

#include <bits/stdc++.h>

using namespace std;

vector<string> board;

void Traverse(int y, int x, int n) {
  if (n == 3) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i == 1 && j == 1) continue;
        board[y + i][x + j] = '*';
      }
    }
    return;
  }

  n /= 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1) continue;
      Traverse(y + i * n, x + j * n, n);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  board.resize(n, string(n, ' '));
  Traverse(0, 0, n);

  for (auto& s : board) cout << s << "\n";

  return 0;
}
