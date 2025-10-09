// Title : 파일 합치기
// Link  : https://www.acmicpc.net/problem/11066 
// Time  : 288 ms
// Memory: 5980 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int64_t>> memo(n, vector<int64_t>(n));
    vector<vector<int64_t>> cost(n, vector<int64_t>(n));
    for (int i = 0; i < n; i++) {
      cin >> memo[0][i];
    }

    for (int i = 0; i + 1 < n; i++) {
      int clen = i + 1, nlen = i + 2;
      for (int j = 0; j + nlen <= n; j++) {
        pair<int64_t, int64_t> cur{kInf, 0};
        for (int k = 1; k < nlen; k++) {
          pair<int64_t, int64_t> val;

          val.first = memo[k - 1][j] + memo[nlen - k - 1][j + k];
          val.second = cost[k - 1][j] + cost[nlen - k - 1][j + k] + val.first;
          if (cur > val) cur = val;
        }
        memo[i + 1][j] = cur.first;
        cost[i + 1][j] = cur.second;
      }
    }
    cout << cost[n - 1][0] << "\n";
  }

  return 0;
}