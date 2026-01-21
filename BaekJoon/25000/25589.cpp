// Title : 푸앙이와 코인
// Link  : https://www.acmicpc.net/problem/25589 
// Time  : 132 ms
// Memory: 5852 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int64_t>> mat(n + 1, vector<int64_t>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1] + x;
    }
  }

  vector<vector<int64_t>> m1(n + 1, vector<int64_t>(n + 1)), m2(n + 1, vector<int64_t>(n + 1));
  for (int len = 1; len <= n; len++) {
    int64_t sub = (int64_t)len * len * len * len;
    for (int y = 0; y + len <= n; y++) {
      for (int x = 0; x + len <= n; x++) {
        int yy = y + len, xx = x + len;
        int64_t v = mat[yy][xx] - mat[yy][x] - mat[y][xx] + mat[y][x] - sub;
        m1[yy][xx] = max<int64_t>({m1[yy][xx], m1[yy - 1][xx], m1[yy][xx - 1], v});
      }
    }
  }

  for (int len = 1; len <= n; len++) {
    int64_t sub = (int64_t)len * len * len * len;
    for (int y = n - len; y >= 0; y--) {
      for (int x = n - len; x >= 0; x--) {
        int yy = y + len, xx = x + len;
        int64_t v = mat[y][x] - mat[y][xx] - mat[yy][x] + mat[yy][xx] - sub;
        m2[y][x] = max<int64_t>({m2[y][x], m2[y + 1][x], m2[y][x + 1], v});
      }
    }
  }

  int64_t maxx = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == n && j == n) continue;
      maxx = max<int64_t>(maxx, m1[i][j] + max<int64_t>(m2[i][0], m2[0][j]));
    }
  }
  cout << maxx;

  return 0;
}