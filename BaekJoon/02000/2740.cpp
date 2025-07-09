// Title : 행렬 곱셈
// Link  : https://www.acmicpc.net/problem/2740 
// Time  : 0 ms
// Memory: 2152 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m;
  vector<vector<int>> m1(n, vector<int>(m));
  for (auto& vec : m1) {
    for (auto& e : vec) cin >> e;
  }

  cin >> m >> k;
  vector<vector<int>> m2(m, vector<int>(k));
  for (auto& vec : m2) {
    for (auto& e : vec) cin >> e;
  }

  vector<vector<int>> m3(n, vector<int>(k));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      for (int l = 0; l < m; l++) {
        m3[i][j] += m1[i][l] * m2[l][j];
      }
    }
  }

  for (auto& vec : m3) {
    for (auto e : vec) cout << e << " ";
    cout << "\n";
  }

  return 0;
}
