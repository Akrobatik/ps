// Title : 행렬
// Link  : https://www.acmicpc.net/problem/1080 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

char m1[50][50], m2[50][50];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> m1[i][j];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> m2[i][j];
  }

  int cnt = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 2; j++) {
      if (m1[i][j] != m2[i][j]) {
        ++cnt;
        for (int k = 0; k < 3; k++) {
          for (int l = 0; l < 3; l++) {
            m1[i + k][j + l] ^= 1;
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (m1[i][j] != m2[i][j]) {
        cout << "-1";
        return 0;
      }
    }
  }
  cout << cnt;

  return 0;
}
