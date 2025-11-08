// Title : 직사각형 채우기
// Link  : https://www.acmicpc.net/problem/34725 
// Time  : 72 ms
// Memory: 5996 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> mat(n, vector<int>(m));
  int idx = 0;
  int nh = n >> 1, mh = m >> 1;
  for (int i = 0; i < nh; i++) {
    for (int j = 0; j < mh; j++) {
      int cur = ++idx;
      mat[i][j] = cur;
      mat[i][m - j - 1] = cur;
      mat[n - i - 1][j] = cur;
      mat[n - i - 1][m - j - 1] = cur;
    }
  }

  for (auto& vec : mat) {
    for (auto e : vec) cout << e << " ";
    cout << "\n";
  }

  return 0;
}