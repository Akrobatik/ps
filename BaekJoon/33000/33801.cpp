// Title : Game of RUN
// Link  : https://www.acmicpc.net/problem/33801 
// Time  : 12 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

int ans[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t _memo[2][5] = {
      {1, 0, 1, 0, 1},
      {},
  };

  auto memo = _memo[0], mnxt = _memo[1];

  ans[0] = ans[1] = 1;
  for (int i = 2; i <= 1000000; i++) {
    mnxt[0] = (memo[0] + memo[3]) % kMod;
    mnxt[1] = (memo[4] + memo[1]) % kMod;
    mnxt[2] = (memo[1] + memo[2]) % kMod;
    mnxt[3] = (memo[3] + memo[4]) % kMod;
    mnxt[4] = (memo[0] + memo[1] + memo[2] + memo[3] + memo[4]) % kMod;
    ans[i] = (mnxt[1] + mnxt[3] + mnxt[4]) % kMod;
    swap(memo, mnxt);
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << ans[n] << "\n";
  }

  return 0;
}
