#include <bits/stdc++.h>

using namespace std;

int foothold[1000][1000];
int memo[1000][1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c;
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      char c;
      cin >> c;
      switch (c) {
        case 'U':
          foothold[i][j] = ((i - 1) << 16) | j;
          break;
        case 'D':
          foothold[i][j] = ((i + 1) << 16) | j;
          break;
        case 'L':
          foothold[i][j] = (i << 16) | (j - 1);
          break;
        case 'R':
          foothold[i][j] = (i << 16) | (j + 1);
          break;
      }
    }
  }

  int ans = 0;
  int cnt = 1;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (memo[i][j]) continue;

      int cr = i, cc = j;
      while (memo[cr][cc] == 0) {
        int v = foothold[cr][cc];
        memo[cr][cc] = cnt;
        cr = v >> 16;
        cc = v & 0xFFFF;
      }

      if (memo[cr][cc] == cnt++) ++ans;
    }
  }

  cout << ans << endl;

  return 0;
}
