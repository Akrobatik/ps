// Title : 수열과 쿼리 5
// Link  : https://www.acmicpc.net/problem/13547 
// Time  : 132 ms
// Memory: 7896 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int arr[100000], ans[100000], cnt[1000001];
tup queries[100000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    auto& [l, r, q] = queries[i];
    cin >> l >> r;
    --l, --r, q = i;
  }

  int s = sqrt(n);
  sort(queries, queries + m, [&](const tup& lhs, const tup& rhs) {
    auto [ll, lr, lq] = lhs;
    auto [rl, rr, rq] = rhs;
    int ls = ll / s, rs = rl / s;
    return ls < rs || (ls == rs && lr < rr);
  });

  auto [l, r, q] = queries[0];
  int c = 0;
  for (int i = l; i <= r; i++) {
    if (++cnt[arr[i]] == 1) ++c;
  }
  ans[q] = c;

  for (int i = 1; i < m; i++) {
    auto [ll, rr, qq] = queries[i];

    while (ll < l) {
      if (++cnt[arr[--l]] == 1) ++c;
    }
    while (ll > l) {
      if (--cnt[arr[l++]] == 0) --c;
    }

    while (rr < r) {
      if (--cnt[arr[r--]] == 0) --c;
    }
    while (rr > r) {
      if (++cnt[arr[++r]] == 1) ++c;
    }

    ans[qq] = c;
  }

  for (int i = 0; i < m; i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}
