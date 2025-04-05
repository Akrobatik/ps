// Title : 테트로미노
// Link  : https://www.acmicpc.net/problem/14500
// Time  : 196 ms
// Memory: 3004 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

int n, m;
int cells[502][502];

int GetMax(int y, int x, int d) {
  if (d == 4) return 0;

  int tmp = cells[y][x], maxx = 0;
  cells[y][x] = 0;
  for (auto [dy, dx] : kDelta) {
    int yy = y + dy, xx = x + dx;
    if (0 < yy && yy <= n && 0 < xx && xx <= m && cells[yy][xx]) {
      int ret = GetMax(yy, xx, d + 1);
      if (maxx < ret) maxx = ret;
    }
  }

  cells[y][x] = tmp;
  return maxx + tmp;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> cells[i][j];
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int sum = cells[i][j], minn = INT_MAX;
      for (auto [dy, dx] : kDelta) {
        int y = i + dy, x = j + dx;
        sum += cells[y][x];
        if (minn > cells[y][x]) minn = cells[y][x];
      }
      sum -= minn;
      if (ans < sum) ans = sum;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int maxx = GetMax(i, j, 0);
      if (ans < maxx) ans = maxx;
    }
  }
  cout << ans;

  return 0;
}
