// Title : 별 찍기 - 8
// Link  : https://www.acmicpc.net/problem/2445 
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

  vector<string> board(sz, string(sz + 1, ' '));
  for (int i = 0; i < sz; i++) {
    int limit = min<int>(i + 1, sz - i);
    for (int j = 0; j < limit; j++) {
      board[i][j] = board[i][sz - j] = '*';
    }
  }

  for (auto& s : board) cout << s << "\n";

  return 0;
}
