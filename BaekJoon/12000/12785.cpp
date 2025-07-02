// Title : 토쟁이의 등굣길
// Link  : https://www.acmicpc.net/problem/12785 
// Time  : 0 ms
// Memory: 2180 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e6 + 7;

int memo[201][201];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int w, h, x, y;
  cin >> w >> h >> x >> y;

  memo[1][1] = 1;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (i == 1 && j == 1) continue;
      memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
      if (memo[i][j] >= kMod) memo[i][j] -= kMod;
    }
  }

  int a = memo[y][x], b = memo[h - y + 1][w - x + 1];
  cout << (int64_t)a * b % kMod;

  return 0;
}
