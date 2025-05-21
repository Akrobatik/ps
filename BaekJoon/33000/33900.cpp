// Title : 캠핑장 부지 평탄화
// Link  : https://www.acmicpc.net/problem/33900 
// Time  : 60 ms
// Memory: 5996 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, r, c;
  cin >> n >> m >> r >> c;
  vector<vector<int>> amat(n, vector<int>(m)), bmat(r, vector<int>(c));
  for (auto& vec : amat) {
    for (auto& e : vec) cin >> e;
  }
  for (auto& vec : bmat) {
    for (auto& e : vec) cin >> e;
  }

  int cnt = 0;
  for (int i = 0; i + r <= n; i++) {
    for (int j = 0; j + c <= m; j++) {
      int x = amat[i][j] - bmat[0][0];
      bool ok = true;
      for (int k = 0; ok && k < r; k++) {
        for (int l = 0; ok && l < c; l++) {
          ok = (amat[i + k][j + l] - bmat[k][l]) == x;
        }
      }
      cnt += ok;
    }
  }
  cout << cnt;

  return 0;
}