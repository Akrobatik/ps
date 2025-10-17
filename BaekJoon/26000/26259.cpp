// Title : 백룸
// Link  : https://www.acmicpc.net/problem/26259 
// Time  : 100 ms
// Memory: 13852 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[2] = {{0, 1}, {1, 0}};
constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> mat(n, vector<int>(m));
  for (auto& vec : mat) {
    for (auto& e : vec) {
      cin >> e;
    }
  }

  int y1, x1, y2, x2;
  cin >> y1 >> x1 >> y2 >> x2;
  if (y1 > y2) swap(y1, y2);
  if (x1 > x2) swap(x1, x2);

  auto Check = [&](int sy, int sx, int ey, int ex) {
    if (!(0 <= ey && ey < n && 0 <= ex && ex < m)) return false;
    if (y1 == y2 && sy == y1 - 1 && ey == y1 && x1 <= ex && ex < x2) return false;
    if (x1 == x2 && sx == x1 - 1 && ex == x1 && y1 <= ey && ey < y2) return false;
    return true;
  };

  vector<vector<int64_t>> memo(n, vector<int64_t>(m, -kInf));
  memo[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (memo[i][j] == -kInf) continue;
      for (auto [dy, dx] : kDelta) {
        int y = i + dy, x = j + dx;
        if (Check(i, j, y, x)) {
          memo[y][x] = max<int64_t>(memo[y][x], memo[i][j] + mat[i][j]);
        }
      }
    }
  }

  if (memo[n - 1][m - 1] != -kInf) {
    cout << memo[n - 1][m - 1] + mat[n - 1][m - 1];
  } else {
    cout << "Entity";
  }

  return 0;
}