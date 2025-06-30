// Title : 소용돌이 예쁘게 출력하기
// Link  : https://www.acmicpc.net/problem/1022 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto GetValue = [&](int y, int x) {
    int d = max<int>(abs(y), abs(x));
    int r = (d << 1) + 1;
    if (y == d) return r * r + x - d;
    if (y == -d) return (r - 1) * (r - 1) - x - d + 1;
    if (x == d) return (r - 2) * (r - 2) - y + d;
    return (r - 1) * (r - 1) + y + d + 1;
  };

  int r1, c1, r2, c2, maxx = 0;
  cin >> r1 >> c1 >> r2 >> c2;
  vector<vector<int>> board(r2 - r1 + 1, vector<int>(c2 - c1 + 1));
  for (int i = r1; i <= r2; i++) {
    for (int j = c1; j <= c2; j++) {
      board[i - r1][j - c1] = GetValue(i, j);
      maxx = max<int>(maxx, board[i - r1][j - c1]);
    }
  }

  int len = 0;
  while (maxx) maxx /= 10, ++len;

  for (auto& vec : board) {
    for (auto e : vec) {
      cout << setw(len) << setfill(' ') << e << " ";
    }
    cout << "\n";
  }

  return 0;
}
