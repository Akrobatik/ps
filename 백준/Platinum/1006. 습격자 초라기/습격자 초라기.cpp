#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int> GetNear(int pos, int n) {
  return pos < n ? make_tuple(pos != 0 ? pos - 1 : n - 1, pos + 1 != n ? pos + 1 : 0, pos + n)
                 : make_tuple(pos != n ? pos - 1 : (n << 1) - 1, pos + 1 != (n << 1) ? pos + 1 : n, pos - n);
}

int n, w;
int enemies[10001][2];
int memo[10001][3];

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

void Solve() {
  cin >> n >> w;
  for (int i = 1; i <= n; i++) cin >> enemies[i][0];
  for (int i = 1; i <= n; i++) cin >> enemies[i][1];

  memo[1][0] = memo[1][1] = 1;
  memo[1][2] = 2 - (enemies[1][0] + enemies[1][1] <= w);
  int ans = Traverse();
  if (n >= 2) {
    memo[1][2] = 2;
    if (enemies[1][0] + enemies[n][0] <= w) {
      int tmp[] = {enemies[1][0], enemies[n][0]};
      enemies[1][0] = enemies[n][0] = 10001;
      int v = Traverse() - 1;
      if (ans > v) ans = v;
      enemies[1][0] = tmp[0];
      enemies[n][0] = tmp[1];
    }

    if (enemies[1][1] + enemies[n][1] <= w) {
      int tmp[] = {enemies[1][1], enemies[n][1]};
      enemies[1][1] = enemies[n][1] = 10001;
      int v = Traverse() - 1;
      if (ans > v) ans = v;
      enemies[1][1] = tmp[0];
      enemies[n][1] = tmp[1];
    }

    if (enemies[1][0] + enemies[n][0] <= w && enemies[1][1] + enemies[n][1] <= w) {
      int tmp[] = {enemies[1][0], enemies[1][1], enemies[n][0], enemies[n][1]};
      enemies[1][0] = enemies[1][1] = enemies[n][0] = enemies[n][1] = 10001;
      int v = Traverse() - 2;
      if (ans > v) ans = v;
      enemies[1][0] = tmp[0];
      enemies[1][1] = tmp[1];
      enemies[n][0] = tmp[2];
      enemies[n][1] = tmp[3];
    }
  }

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) Solve();

  return 0;
}
