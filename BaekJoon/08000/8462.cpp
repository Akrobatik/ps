// Title : 배열의 힘
// Link  : https://www.acmicpc.net/problem/8462 
// Time  : 208 ms
// Memory: 8292 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  vector<tup> queries(t);
  for (int i = 0; i < t; i++) {
    auto& [l, r, q] = queries[i];
    cin >> l >> r;
    --l, --r, q = i;
  }

  vector<int64_t> ans(t);
  vector<int> cnt(1e6 + 1);

  int64_t sum = 0;

  auto Calc = [&](int x) {
    return (int64_t)cnt[x] * cnt[x] * x;
  };

  auto Add = [&](int x) {
    x = arr[x];
    int64_t old = Calc(x);
    ++cnt[x];
    int64_t cur = Calc(x);
    sum += cur - old;
  };

  auto Sub = [&](int x) {
    x = arr[x];
    int64_t old = Calc(x);
    --cnt[x];
    int64_t cur = Calc(x);
    sum += cur - old;
  };

  int s = sqrt(n);
  sort(queries.begin(), queries.end(), [&](const tup& lhs, const tup& rhs) {
    auto [ll, lr, lq] = lhs;
    auto [rl, rr, rq] = rhs;
    int ls = ll / s, rs = rl / s;
    return ls < rs || (ls == rs && lr < rr);
  });

  auto [l, r, q] = queries[0];
  for (int i = l; i <= r; i++) {
    Add(i);
  }
  ans[q] = sum;

  for (int i = 1; i < t; i++) {
    auto [ll, rr, qq] = queries[i];
    while (ll < l) Add(--l);
    while (ll > l) Sub(l++);
    while (rr < r) Sub(r--);
    while (rr > r) Add(++r);
    ans[qq] = sum;
  }

  for (auto e : ans) cout << e << "\n";

  return 0;
}
