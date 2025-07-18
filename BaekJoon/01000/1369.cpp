// Title : 배열값
// Link  : https://www.acmicpc.net/problem/1369 
// Time  : 108 ms
// Memory: 9956 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> mat2(n + 1, vector<int>(n + 1, INT_MAX >> 1));
  vector<vector<int>> mat5(n + 1, vector<int>(n + 1, INT_MAX >> 1));
  mat2[0][1] = mat5[0][1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      if (x == 0) continue;

      int c2 = 0, c5 = 0;
      while (x % 2 == 0) x /= 2, ++c2;
      while (x % 5 == 0) x /= 5, ++c5;
      mat2[i][j] = min<int>(mat2[i - 1][j], mat2[i][j - 1]) + c2;
      mat5[i][j] = min<int>(mat5[i - 1][j], mat5[i][j - 1]) + c5;
    }
  }
  cout << min<int>(mat2[n][n], mat5[n][n]);

  return 0;
}
