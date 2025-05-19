// Title : 쿠키런
// Link  : https://www.acmicpc.net/problem/33925 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, j, s, h, k;
  cin >> n >> j >> s >> h >> k;
  vector<string> board(3);
  for (auto& s : board) cin >> s;

  int top = 0, lo = 0, hi = 0;
  for (int i = 0; i < n; i++) {
    if (board[0][i] == 'v') {
      ++top;
    } else if (board[1][i] == '^') {
      ++hi;
    } else if (board[2][i] == '^') {
      ++lo;
    }
  }

  int all = top + lo + hi;
  int tx = min<int>(s, top);
  int lx = min<int>(j, lo);
  int hx = min<int>((j - lx) >> 1, hi);
  int hit = all - tx - lx - hx;
  int rem = h - hit * k;
  cout << (rem > 0 ? rem : -1);

  return 0;
}