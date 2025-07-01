// Title : 별 찍기 - 17
// Link  : https://www.acmicpc.net/problem/10992 
// Time  : 0 ms
// Memory: 2152 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> board(n, string((n << 1) - 1, ' '));
  for (int i = 0; i < n; i++) {
    board[i][n - i - 1] = board[i][n + i - 1] = '*';
  }
  for (auto& c : board.back()) c = '*';

  for (auto& s : board) {
    while (s.back() == ' ') s.pop_back();
    cout << s << "\n";
  }

  return 0;
}
