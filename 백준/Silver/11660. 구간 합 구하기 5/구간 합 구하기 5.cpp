#include <bits/stdc++.h>

using namespace std;

uint32_t memo[1025][1025];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int y = 1; y <= n; y++) {
    int sum = 0;
    for (int x = 1; x <= n; x++) {
      int v;
      cin >> v;
      sum += v;
      memo[y][x] = memo[y - 1][x] + sum;
    }
  }

  for (int i = 0; i < m; i++) {
    int x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << memo[y2][x2] - memo[y2][x1 - 1] - memo[y1 - 1][x2] + memo[y1 - 1][x1 - 1] << "\n";
  }

  return 0;
}
