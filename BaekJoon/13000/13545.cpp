// Title : 수열과 쿼리 0
// Link  : https://www.acmicpc.net/problem/13545 
// Time  : 392 ms
// Memory: 8696 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  ++n;
  int k = n << 1;
  vector<int> axr(n + 1);
  axr[1] = n;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    axr[i] = axr[i - 1] + x;
  }

  vector<int> arr(n + 1), nxt(n + 1), prv(n + 1);
  vector<int> memo(k + 1);
  for (int i = 1; i <= n; i++) {
    arr[i] = axr[i];
    prv[i] = memo[arr[i]];
    memo[arr[i]] = nxt[prv[i]] = i;
  }

  int m;
  cin >> m;
  vector<tup> queries(m);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    queries[i] = {l, r + 1, i};
  }

  int s = sqrt(n) + 1;
  sort(queries.begin(), queries.end(), [&](const tup& lhs, const tup& rhs) {
    auto [ll, lr, lq] = lhs;
    auto [rl, rr, rq] = rhs;
    int ls = ll / s, rs = rl / s;
    return ls < rs || (ls == rs && lr < rr);
  });

  vector<int> freq(n + 1), bkt(s + 1);
  vector<int> cnt(k + 1);
  vector<pair<int, int>> lr(k + 1);

  auto Add = [&](int x) {
    ++bkt[x / s];
    ++freq[x];
  };

  auto Sub = [&](int x) {
    --bkt[x / s];
    --freq[x];
  };

  auto Push = [&](int i, int dir) {
    int x = arr[i];
    if (cnt[x]++ == 0) {
      lr[x] = {i, i};
      Add(0);
    } else {
      auto& [l, r] = lr[x];
      Sub(r - l);
      if (dir == 1) {
        r = i;
      } else {
        l = i;
      }
      Add(r - l);
    }
  };

  auto Pop = [&](int i, int dir) {
    int x = arr[i];
    if (--cnt[x] == 0) {
      Sub(0);
    } else {
      auto& [l, r] = lr[x];
      Sub(r - l);
      if (dir == 1) {
        r = prv[i];
      } else {
        l = nxt[i];
      }
      Add(r - l);
    }
  };

  auto Get = [&]() {
    for (int i = s; i >= 0; i--) {
      if (bkt[i] == 0) continue;
      int x = min<int>((i + 1) * s, n + 1);
      while (x--) {
        if (freq[x]) return x;
      }
    }
    return 0;
  };

  vector<int> ans(m);
  auto [l, r, q] = queries[0];
  for (int i = l; i <= r; i++) {
    Push(i, 1);
  }
  ans[q] = Get();

  for (int i = 1; i < m; i++) {
    auto [ll, rr, qq] = queries[i];
    while (ll < l) Push(--l, -1);
    while (rr > r) Push(++r, 1);
    while (ll > l) Pop(l++, -1);
    while (rr < r) Pop(r--, 1);
    ans[qq] = Get();
  }

  for (auto e : ans) cout << e << "\n";

  return 0;
}
