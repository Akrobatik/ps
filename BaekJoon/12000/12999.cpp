// Title : 화려한 마을3
// Link  : https://www.acmicpc.net/problem/12999 
// Time  : 392 ms
// Memory: 5168 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kPad = 1e5;
constexpr int kMax = 2e5;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    arr[i] = x + kPad;
  }

  int s = sqrt(n) + 1;
  vector<int> bkts(s), cnts(n + 1), val(kMax + 1);
  bkts[0] = n, cnts[0] = n;

  auto Push = [&](int i) {
    int x = arr[i];
    int old = val[x];
    int cur = ++val[x];
    --cnts[old], --bkts[old / s];
    ++cnts[cur], ++bkts[cur / s];
  };

  auto Pop = [&](int i) {
    int x = arr[i];
    int old = val[x];
    int cur = --val[x];
    --cnts[old], --bkts[old / s];
    ++cnts[cur], ++bkts[cur / s];
  };

  auto Get = [&]() {
    for (int i = s - 1; i >= 0; i--) {
      if (bkts[i] == 0) continue;

      int idx = (i + 1) * s - 1;
      while (cnts[idx] == 0) --idx;
      return idx;
    }
  };

  vector<tup> queries(m);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    queries[i] = {l, r, i};
  }
  sort(queries.begin(), queries.end(), [&](const tup& lhs, const tup& rhs) {
    auto [ll, lr, lq] = lhs;
    auto [rl, rr, rq] = rhs;
    int ls = ll / s, rs = rl / s;
    return ls < rs || (ls == rs && lr < rr);
  });

  vector<int> ans(m);

  auto [l, r, q] = queries[0];
  for (int i = l; i <= r; i++) {
    Push(i);
  }
  ans[q] = Get();

  for (int i = 1; i < m; i++) {
    auto [ll, rr, qq] = queries[i];
    while (ll < l) Push(--l);
    while (rr > r) Push(++r);
    while (ll > l) Pop(l++);
    while (rr < r) Pop(r--);
    ans[qq] = Get();
  }

  for (auto e : ans) cout << e << "\n";

  return 0;
}