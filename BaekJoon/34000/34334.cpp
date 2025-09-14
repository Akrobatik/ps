// Title : 화단 꾸미기
// Link  : https://www.acmicpc.net/problem/34334 
// Time  : 84 ms
// Memory: 2836 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    arr[i] = arr[i - 1] + x;
  }

  vector<int> brr(m);
  for (auto& e : brr) cin >> e, --e;

  int limit = 1 << m;
  vector<vector<int64_t>> memo(n + 1, vector<int64_t>(limit, -kInf));
  memo[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < limit; j++) {
      int64_t val = memo[i][j];
      if (val == -kInf) continue;

      memo[i + 1][j] = max<int64_t>(memo[i + 1][j], val);
      for (int l = 1; l <= k && i + l <= n; l++) {
        int64_t sum = arr[i + l] - arr[i];
        int b = (~j) & (limit - 1);
        while (b) {
          int lsb = b & (-b);
          b ^= lsb;
          memo[i + l][j | lsb] = max<int64_t>(memo[i + l][j | lsb], val + sum * brr[countr_zero((uint32_t)lsb)]);
        }
      }
    }
  }

  int64_t maxx = 0;
  for (int i = 0; i < limit; i++) {
    maxx = max<int64_t>(maxx, memo[n][i]);
  }
  cout << maxx + arr[n];

  return 0;
}
