// Title : 별 찍기 - 21
// Link  : https://www.acmicpc.net/problem/10996 
// Time  : 0 ms
// Memory: 2152 KB

#include <bits/stdc++.h>

using namespace std;

vector<string> board;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int h = n << 1, w = n;
  vector<string> board(h, string(w, ' '));

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if ((i + j) & 1) continue;
      board[i][j] = '*';
    }
  }

  for (auto& s : board) {
    while (s.back() == ' ') s.pop_back();
    cout << s << "\n";
  }

  return 0;
}
