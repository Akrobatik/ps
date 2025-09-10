// Title : 마리오 파티
// Link  : https://www.acmicpc.net/problem/14550 
// Time  : 0 ms
// Memory: 2152 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = INT_MAX >> 1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s, t;
  while (cin >> n >> s >> t) {
    vector<int> arr(n + 2);
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }

    vector<vector<int>> memo(t + 1, vector<int>(n + 2, -kInf));
    memo[0][0] = 0;

    for (int i = 1; i <= n + 1; i++) {
      for (int j = 1; i - j >= 0 && j <= s; j++) {
        for (int k = 0; k < t; k++) {
          memo[k + 1][i] = max<int>(memo[k + 1][i], memo[k][i - j] + arr[i]);
        }
      }
    }

    int maxx = -kInf;
    for (int i = 0; i <= t; i++) {
      maxx = max<int>(maxx, memo[i][n + 1]);
    }
    cout << maxx << "\n";
  }

  return 0;
}
