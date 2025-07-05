// Title : 별 찍기 - 16
// Link  : https://www.acmicpc.net/problem/10991 
// Time  : 0 ms
// Memory: 2152 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int sz = (n << 1) - 1;

  vector<string> board(n, string(sz, ' '));
  for (int i = 0; i < n; i++) {
    int limit = min<int>(i + 1, sz - i);
    for (int j = limit - 1; j >= 0; j -= 2) {
      board[i][n - j - 1] = board[i][n + j - 1] = '*';
    }
  }

  for (auto& s : board) {
    while (s.back() == ' ') s.pop_back();
    cout << s << "\n";
  }

  return 0;
}
