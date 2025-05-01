// Title : 1, 2, 3 더하기 7
// Link  : https://www.acmicpc.net/problem/15992 
// Time  : 12 ms
// Memory: 5936 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 9;

int memo[1001][1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  memo[0][0] = 1;
  for (int i = 1; i <= 1000; i++) {
    int limit = min<int>(i * 3, 1000);
    for (int j = 1; j <= limit; j++) {
      for (auto k : {1, 2, 3}) {
        if (j < k) break;
        memo[j][i] = (memo[j][i] + memo[j - k][i - 1]) % kMod;
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    cout << memo[n][m] << "\n";
  }

  return 0;
}
