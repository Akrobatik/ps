// Title : 행렬 곱셈 순서
// Link  : https://www.acmicpc.net/problem/11049
// Time  : 28 ms
// Memory: 3004 KB

#include <bits/stdc++.h>

using namespace std;

int mat[501][2];
int memo[501][501];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> mat[i][0] >> mat[i][1];

  for (int i = 1; i < n; i++) {
    for (int j = 1; i + j <= n; j++) {
      memo[j][i + j] = INT_MAX;
      for (int k = j; k <= i + j; k++)
        memo[j][i + j] = min<int>(memo[j][i + j],
                                  memo[j][k] + memo[k + 1][i + j] + mat[j][0] * mat[k][1] * mat[i + j][1]);
    }
  }

  cout << memo[1][n] << endl;

  return 0;
}
