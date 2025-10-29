// Title : 알고리즘 수업 - 행렬 경로 문제 3
// Link  : https://www.acmicpc.net/problem/24426 
// Time  : 104 ms
// Memory: 21760 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

constexpr pair<int, int> kDelta[] = {
    {1, 0}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> mat(n, vector<int>(n));
  for (auto& vec : mat) {
    for (auto& e : vec) cin >> e;
  }

  int my, mx;
  cin >> my >> mx, --my, --mx;

  vector<vector<array<int64_t, 2>>> memo(n, vector<array<int64_t, 2>>(n, {-kInf, -kInf}));
  memo[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 2; k++) {
        int nk = k || (i == my && j == mx);
        for (auto [dy, dx] : kDelta) {
          int y = i + dy, x = j + dx;
          if (0 <= y && y < n && 0 <= x && x < n) {
            memo[y][x][nk] = max<int64_t>(memo[y][x][nk], memo[i][j][k] + mat[i][j]);
          }
        }
      }
    }
  }

  for (int i = 0; i < 2; i++) {
    cout << memo[n - 1][n - 1][i ^ 1] + mat[n - 1][n - 1] << " ";
  }

  return 0;
}