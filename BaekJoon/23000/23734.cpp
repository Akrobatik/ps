// Title : Miswritten DFS
// Link  : https://www.acmicpc.net/problem/23734 
// Time  : 20 ms
// Memory: 9000 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;

  vector<array<int, 2>> lr(n + 1);
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    lr[i] = {l, r};
  }

  vector<array<int64_t, 2>> memo(n + 1);
  [&](this auto&& self, int cur) -> int64_t {
    int64_t sum = 0;
    for (int i = 0; i < 2; i++) {
      if (lr[cur][i] == 0) continue;
      int64_t cnt = self(lr[cur][i]);
      memo[cur][i] = cnt;
      sum += cnt * (2 - i);
    }
    return min<int64_t>(sum + 1, k + 1);
  }(1);

  cout << [&](this auto&& self, int cur) -> int {
    if (--k == 0) return cur;

    int64_t val[3] = {memo[cur][0], memo[cur][0], memo[cur][1]};
    for (int i = 0; i < 3; i++) {
      if (k <= val[i]) return self(i < 2 ? lr[cur][0] : lr[cur][1]);
      k -= val[i];
    }
    assert(0);
  }(1);

  return 0;
}
