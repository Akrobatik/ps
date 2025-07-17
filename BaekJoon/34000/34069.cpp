// Title : 자리 바꾸기
// Link  : https://www.acmicpc.net/problem/34069 
// Time  : 44 ms
// Memory: 3080 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  if (n * m & 1) {
    cout << "No";
    return 0;
  }

  vector<vector<int>> mat(n, vector<int>(m));
  for (auto& vec : mat) {
    for (auto& e : vec) cin >> e;
  }

  if (~n & 1) {
    for (int i = 0; i < n; i += 2) {
      for (int j = 0; j < m; j++) {
        swap(mat[i][j], mat[i + 1][j]);
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j += 2) {
        swap(mat[i][j], mat[i][j + 1]);
      }
    }
  }

  cout << "Yes\n";
  for (auto& vec : mat) {
    for (auto e : vec) cout << e << " ";
    cout << "\n";
  }

  return 0;
}
