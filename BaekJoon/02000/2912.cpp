// Title : 백설공주와 난쟁이
// Link  : https://www.acmicpc.net/problem/2912 
// Time  : 660 ms
// Memory: 5872 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, c;
  cin >> n >> c;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int maxx = 0, type = 0;
  vector<int> cnts(c + 1), _memo((n << 1) + 1);
  auto memo = _memo.data() + n;
  cnts[0] = n;

  auto Add = [&](int i) {
    int x = ++cnts[arr[i]];
    --memo[x - 1];
    ++memo[x];
    if (maxx < x) maxx = x, type = arr[i];
  };

  auto Sub = [&](int i) {
    int x = --cnts[arr[i]];
    if (--memo[x + 1] == 0 && x + 1 == maxx) --maxx, type = 0;
    ++memo[x];
  };

  auto Find = [&](int l, int r) {
    int n = r - l + 1;
    if ((n >> 1) >= maxx) return 0;
    if (type) return type;
    for (int i = 1; i <= c; i++) {
      if (cnts[i] == maxx) return i;
    }
  };

  int m, sqr = sqrt((double)n);
  cin >> m;
  vector<tup> queries(m);
  vector<int> ans(m);
  for (int i = 0; i < m; i++) {
    auto& [l, r, s, q] = queries[i];
    cin >> l >> r;
    --l, --r;
    s = l / sqr;
    q = i;
  }

  sort(queries.begin(), queries.end(), [](const tup& lhs, const tup& rhs) {
    auto [ll, lr, ls, lq] = lhs;
    auto [rl, rr, rs, rq] = rhs;
    return ls < rs || (ls == rs && lr > rr);
  });

  auto [l, r, _, q] = queries[0];
  for (int i = l; i <= r; i++) {
    Add(i);
  }
  ans[q] = Find(l, r);

  for (int i = 1; i < m; i++) {
    auto [ll, rr, _, qq] = queries[i];
    while (ll > l) Sub(l++);
    while (rr < r) Sub(r--);
    while (ll < l) Add(--l);
    while (rr > r) Add(++r);
    ans[qq] = Find(l, r);
  }

  for (auto e : ans) {
    if (e) {
      cout << "yes " << e << "\n";
    } else {
      cout << "no\n";
    }
  }

  return 0;
}
