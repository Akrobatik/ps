// Title : 화려한 마을2
// Link  : https://www.acmicpc.net/problem/12986 
// Time  : 236 ms
// Memory: 5168 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kPad = 1e5;
constexpr int kMax = kPad << 1;

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

  vector<tup> queries(m);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    queries[i] = {l, r, i};
  }

  int s = sqrt(n) + 1;
  sort(queries.begin(), queries.end(), [&](const tup& lhs, const tup& rhs) {
    auto [ll, lr, lq] = lhs;
    auto [rl, rr, rq] = rhs;
    int ls = ll / s, rs = rl / s;
    return ls < rs || (ls == rs && lr < rr);
  });

  int maxx = 0;
  vector<int> cnt(kMax + 1), freq(n + 1);

  auto Push = [&](int i) {
    int x = arr[i];
    int old = cnt[x], cur = ++cnt[x];
    --freq[old], ++freq[cur];
    maxx = max<int>(maxx, cur);
  };

  auto Pop = [&](int i) {
    int x = arr[i];
    int old = cnt[x], cur = --cnt[x];
    --freq[old], ++freq[cur];
    if (maxx == old && freq[old] == 0) --maxx;
  };

  auto Max = [&]() {
    return maxx;
  };

  vector<int> ans(m);
  auto [l, r, q] = queries[0];
  for (int i = l; i <= r; i++) {
    Push(i);
  }
  ans[q] = Max();

  for (int i = 1; i < m; i++) {
    auto [ll, rr, qq] = queries[i];
    while (ll < l) Push(--l);
    while (rr > r) Push(++r);
    while (ll > l) Pop(l++);
    while (rr < r) Pop(r--);
    ans[qq] = Max();
  }

  for (auto e : ans) cout << e << "\n";

  return 0;
}
