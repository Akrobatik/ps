// Title : 벽 부수고 이동하기 4
// Link  : https://www.acmicpc.net/problem/16946
// Time  : 108 ms
// Memory: 32580 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kDeltaY[] = {1, -1, 0, 0};
constexpr int kDeltaX[] = {0, 0, 1, -1};

int mat[1002][1002];
int memo[1 << 20];
int g_size[1 << 20];

void Traverse(int y, int x, int id, int& depth) {
  if (memo[(y << 10) | x]) return;
  memo[y << 10 | x] = id;
  ++depth;

  for (int i = 0; i < 4; i++) {
    int yy = y + kDeltaY[i];
    int xx = x + kDeltaX[i];
    if (mat[yy][xx] == 0) Traverse(yy, xx, id, depth);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      mat[i][j] = c - '0';
    }
  }
  for (int i = 0; i <= n + 1; i++) mat[i][0] = mat[i][m + 1] = 1;
  for (int i = 0; i <= m + 1; i++) mat[0][i] = mat[n + 1][i] = 1;

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mat[i][j] == 0 && memo[(i << 10) | j] == 0) {
        int depth = 0;
        Traverse(i, j, ++cnt, depth);
        g_size[cnt] = depth;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mat[i][j]) {
        int sum = 1;
        vector<int> gs;
        for (int k = 0; k < 4; k++) {
          int yy = i + kDeltaY[k];
          int xx = j + kDeltaX[k];
          if (mat[yy][xx] == 0 && find(gs.begin(), gs.end(), memo[(yy << 10) | xx]) == gs.end()) {
            sum += g_size[memo[(yy << 10) | xx]];
            gs.push_back(memo[(yy << 10) | xx]);
          }
        }
        mat[i][j] = sum;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << mat[i][j] % 10;
    cout << "\n";
  }

  return 0;
}
