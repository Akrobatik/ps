// Title : $39420$
// Link  : https://www.acmicpc.net/problem/35145 
// Time  : 292 ms
// Memory: 6000 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> mat(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      mat[i][j] = c - '0';
    }
  }

  auto Check = [&](int y, int x, int by, int bx) {
    if (y + by > n || x + bx > m) return false;

    int cnt[10] = {};
    for (int i = 0; i < by; i++) {
      for (int j = 0; j < bx; j++) {
        if (++cnt[mat[y + i][x + j]] > 1) return false;
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

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (auto [by, bx] : cands) {
        cnt += Check(i, j, by, bx);
      }
    }
  }
  cout << cnt;

  return 0;
}