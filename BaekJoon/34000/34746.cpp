// Title : Squid Game: Two Bridges
// Link  : https://www.acmicpc.net/problem/34746 
// Time  : 24 ms
// Memory: 10620 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<array<int, 2>> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i][0];
  }
  for (int i = 1; i <= n; i++) {
    cin >> arr[i][1];
  }

  array<int64_t, 10> init{};
  init.fill(-kInf);
  vector<array<int64_t, 10>> memo(n + 1, init);
  memo[0][k << 1] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int l = 0; l <= k; l++) {
        int key = l << 1 | j;
        int64_t cur = memo[i][key];
        if (cur == -kInf) continue;
        memo[i + 1][key] = max<int64_t>(memo[i + 1][key], cur + arr[i + 1][j]);

        if (l > 0) {
          key = (l - 1) << 1 | (j ^ 1);
          memo[i + 1][key] = max<int64_t>(memo[i + 1][key], cur + arr[i + 1][j ^ 1]);
        }
      }
    }
  }

  cout << *max_element(memo[n].begin(), memo[n].end());

  return 0;
}