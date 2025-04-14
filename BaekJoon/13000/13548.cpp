// Title : 수열과 쿼리 6
// Link  : https://www.acmicpc.net/problem/13548 
// Time  : 128 ms
// Memory: 4772 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int arr[100000], ans[100000], memo[100001], cnt[100001];
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

  int maxx = 0;
  memo[0] = n;
  auto Add = [&](int i) {
    int x = ++cnt[arr[i]];
    --memo[x - 1];
    ++memo[x];
    maxx = max<int>(maxx, x);
  };

  auto Sub = [&](int i) {
    int x = --cnt[arr[i]];
    if (--memo[x + 1] == 0 && x + 1 == maxx) --maxx;
    ++memo[x];
  };

  auto [l, r, q] = queries[0];

  for (int i = l; i <= r; i++) {
    Add(i);
  }
  ans[q] = maxx;

  for (int i = 1; i < m; i++) {
    auto [ll, rr, qq] = queries[i];
    while (ll < l) Add(--l);
    while (ll > l) Sub(l++);
    while (rr < r) Sub(r--);
    while (rr > r) Add(++r);
    ans[qq] = maxx;
  }

  for (int i = 0; i < m; i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}
