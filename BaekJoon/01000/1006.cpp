// Title : 습격자 초라기
// Link  : https://www.acmicpc.net/problem/1006 
// Time  : 72 ms
// Memory: 2292 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = 1 << 16;

int n, w;
int _enemies[20001][2];
int memo[10001][3];
int (*enemies)[2];

int Traverse() {
  for (int i = 2; i <= n; i++) {
    int v1 = 2 - (enemies[i][0] + enemies[i - 1][0] <= w);
    int v2 = 2 - (enemies[i][1] + enemies[i - 1][1] <= w);
    int v3 = 2 - (enemies[i][0] + enemies[i][1] <= w);
    memo[i][0] = min<int>(memo[i - 1][1] + v1, memo[i - 1][2] + 1);
    memo[i][1] = min<int>(memo[i - 1][0] + v2, memo[i - 1][2] + 1);
    memo[i][2] = min<int>({memo[i - 1][2] + v3, memo[i - 2][2] + v1 + v2, memo[i - 1][1] + v1 + 1, memo[i - 1][0] + v2 + 1});
  }
  return memo[n][2];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) cin >> _enemies[i][0], _enemies[i + n][0] = _enemies[i][0];
    for (int i = 1; i <= n; i++) cin >> _enemies[i][1], _enemies[i + n][1] = _enemies[i][1];
    _enemies[0][0] = _enemies[n][0];
    _enemies[0][1] = _enemies[n][1];

    enemies = _enemies;
    for (int i = 0; i < n; i++) {
      int opt = (_enemies[i][0] + _enemies[i + 1][0] <= w);
      opt |= (_enemies[i][1] + _enemies[i + 1][1] <= w) << 1;
      if (opt == 3) continue;
      enemies = _enemies + i;
      if (opt == 0) break;
    }

    memo[1][0] = memo[1][1] = 1;
    memo[1][2] = 2 - (enemies[1][0] + enemies[1][1] <= w);
    int ans = Traverse();
    if (n >= 2) {
      memo[1][2] = 2;
      if (enemies[1][0] + enemies[n][0] <= w) {
        enemies[1][0] |= kInf;
        enemies[n][0] |= kInf;

        int v = Traverse() - 1;
        if (ans > v) ans = v;

        enemies[1][0] ^= kInf;
        enemies[n][0] ^= kInf;
      }

      if (enemies[1][1] + enemies[n][1] <= w) {
        enemies[1][1] |= kInf;
        enemies[n][1] |= kInf;

        int v = Traverse() - 1;
        if (ans > v) ans = v;

        enemies[1][1] ^= kInf;
        enemies[n][1] ^= kInf;
      }

      if (enemies[1][0] + enemies[n][0] <= w && enemies[1][1] + enemies[n][1] <= w) {
        enemies[1][0] |= kInf;
        enemies[1][1] |= kInf;
        enemies[n][0] |= kInf;
        enemies[n][1] |= kInf;

        int v = Traverse() - 2;
        if (ans > v) ans = v;

        enemies[1][0] ^= kInf;
        enemies[1][1] ^= kInf;
        enemies[n][0] ^= kInf;
        enemies[n][1] ^= kInf;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
