// Title : 숫자 박스
// Link  : https://www.acmicpc.net/problem/1983 
// Time  : 400 ms
// Memory: 260232 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr, brr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x) arr.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x) brr.push_back(x);
  }

  int na = arr.size(), nb = brr.size();
  vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(na + 1, vector<int>(nb + 1, INT_MIN / 2)));
  memo[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= na; j++) {
      for (int k = 0; k <= nb; k++) {
        memo[i][j][k] = max<int>(memo[i][j][k], memo[i - 1][j][k]);
        if (j > 0) memo[i][j][k] = max<int>(memo[i][j][k], memo[i - 1][j - 1][k]);
        if (k > 0) memo[i][j][k] = max<int>(memo[i][j][k], memo[i - 1][j][k - 1]);
        if (j > 0 && k > 0) memo[i][j][k] = max<int>(memo[i][j][k], memo[i - 1][j - 1][k - 1] + arr[j - 1] * brr[k - 1]);
      }
    }
  }
  cout << memo[n][na][nb];

  return 0;
}