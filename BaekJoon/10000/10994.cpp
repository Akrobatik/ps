// Title : 별 찍기 - 19
// Link  : https://www.acmicpc.net/problem/10994 
// Time  : 0 ms
// Memory: 2284 KB

#include <bits/stdc++.h>

using namespace std;

vector<string> board;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int h = n * 4 - 3, w = h;
  vector<string> board(h, string(w, ' '));

  int half = h >> 1;
  for (int i = 0; i < n; i++) {
    int sz = i << 1;
    for (int j = -sz; j <= sz; j++) {
      board[half + j][half - sz] = board[half - sz][half + j] = board[half + j][half + sz] = board[half + sz][half + j] = '*';
    }
  }

  for (auto& s : board) {
    while (s.back() == ' ') s.pop_back();
    cout << s << "\n";
  }

  return 0;
}
