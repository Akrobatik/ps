// Title : $-02493$
// Link  : https://www.acmicpc.net/problem/35147 
// Time  : 704 ms
// Memory: 2184 KB

#include <bits/stdc++.h>

using namespace std;

int mat[20][20];
int memo[4][10][10][10][10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto Check = [&](int y, int x, int by, int bx) {
    if (y - by + 1 < 0 || x - bx + 1 < 0) return false;

    int cnt[10] = {};
    for (int i = 0; i < by; i++) {
      for (int j = 0; j < bx; j++) {
        if (++cnt[mat[y - i][x - j]] > 1) return false;
      }
    }
    return true;
  };

  vector<pair<int, int>> cands;
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; i * j <= 10; j++) {
      cands.push_back({i, j});
    }
  }

  for (int a = 0; a < 10; a++) {
    for (int b = 0; b < 10; b++) {
      for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
          mat[i][j] = ((i + 1) * a + (j + 1) * b) % 10;
        }
      }

      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
          int cnt = 0;
          for (auto [by, bx] : cands) {
            cnt += Check(i, j, by, bx);
          }
          memo[0][a][b][i][j] = cnt;
        }
      }

      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
          int cnt = 0;
          for (auto [by, bx] : cands) {
            cnt += Check(i, j + 10, by, bx);
          }
          memo[1][a][b][i][j] = cnt;
        }
      }

      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
          int cnt = 0;
          for (auto [by, bx] : cands) {
            cnt += Check(i + 10, j, by, bx);
          }
          memo[2][a][b][i][j] = cnt;
        }
      }

      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
          int cnt = 0;
          for (auto [by, bx] : cands) {
            cnt += Check(i + 10, j + 10, by, bx);
          }
          memo[3][a][b][i][j] = cnt;
        }
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a %= 10, b %= 10;

    int64_t cnt = 0;
    int yb = min<int>(n, 10), xb = min<int>(m, 10);
    for (int i = 0; i < yb; i++) {
      for (int j = 0; j < xb; j++) {
        int64_t my = (n + 9 - i) / 10, mx = (m + 9 - j) / 10;
        cnt += memo[0][a][b][i][j];
        cnt += (mx - 1) * memo[1][a][b][i][j];
        cnt += (my - 1) * memo[2][a][b][i][j];
        cnt += (mx - 1) * (my - 1) * memo[3][a][b][i][j];
      }
    }
    cout << cnt << " ";
  }

  return 0;
}