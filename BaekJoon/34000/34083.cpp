// Title : 결계 배치하기
// Link  : https://www.acmicpc.net/problem/34083 
// Time  : 108 ms
// Memory: 80336 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 998244353;

int memo[2001][10001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  int d = n / m;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  vector<pair<int, int>> axr(m);
  for (int i = 0; i < m; i++) {
    int l = arr[i * d], r = arr[(i + 1) * d - 1];
    axr[i] = {l, r};
  }

  for (int i = 1; i <= k; i++) memo[1][i] = 1;

  for (int i = 1; i < m; i++) {
    auto [ll, lr] = axr[i - 1];
    auto [rl, rr] = axr[i];
    for (int j = 1; j < rl; j++) {
      int cur = memo[i][j];
      if (cur == 0) continue;

      int lo = max<int>(j + 1, lr + lr - j);
      int hi = rl + rl - j;

      if (lo <= k) {
        if ((memo[i + 1][lo] += cur) >= kMod) memo[i + 1][lo] -= kMod;
      }
      if (hi <= k) {
        if ((memo[i + 1][hi] += kMod - cur) >= kMod) memo[i + 1][hi] -= kMod;
      }
    }
    for (int j = 2; j <= k; j++) {
      if ((memo[i + 1][j] += memo[i + 1][j - 1]) >= kMod) memo[i + 1][j] -= kMod;
    }
  }

  int64_t sum = 0;
  for (int i = 1; i <= k; i++) sum += memo[m][i];
  cout << sum % kMod;

  return 0;
}
