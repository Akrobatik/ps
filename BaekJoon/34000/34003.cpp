// Title : 파이널 서바이버
// Link  : https://www.acmicpc.net/problem/34003 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> board(8);
  int cnt = 0;
  for (auto& s : board) {
    cin >> s;
    cnt += count(s.begin(), s.end(), 'O');
  }

  int maxx = 0, y, x;
  for (int i = 1; i < 8; i++) {
    for (int j = 1; j < 8; j++) {
      int cur = 0;
      for (int k = -1; k <= 0; k++) {
        for (int l = -1; l <= 0; l++) {
          cur += (board[i + k][j + l] == 'O');
        }
      }
      if (maxx < cur) maxx = cur, y = i, x = j;
    }
  }

  int64_t q = 1;
  for (int i = 0; i < 4; i++) {
    q = (q * (cnt - i)) / (i + 1);
  }
  int64_t p;
  if (cnt - maxx < 4) {
    p = 0;
  } else {
    p = 1;
    for (int i = 0; i < 4; i++) {
      p = (p * (cnt - maxx - i)) / (i + 1);
    }
  }

  cout << y << " " << x << "\n"
       << setprecision(6) << fixed << (double)(q - p) / (double)q;

  return 0;
}
