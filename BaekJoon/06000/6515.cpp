// Title : Frequent values
// Link  : https://www.acmicpc.net/problem/6515 
// Time  : 684 ms
// Memory: 5284 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kPad = 1e5;
constexpr int kMax = kPad << 1;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  while (cin >> n >> m) {
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

    vector<int> cnt(kMax + 1);
    vector<int> freq(n + 1), bkt(s + 1);
    cnt[0] = freq[0] = bkt[0] = n;

    auto Add = [&](int x) {
      ++bkt[x / s];
      ++freq[x];
    };

    auto Sub = [&](int x) {
      --bkt[x / s];
      --freq[x];
    };

    auto Push = [&](int i) {
      int x = arr[i];
      int old = cnt[x];
      Sub(old);
      Add(++cnt[x]);
    };

    auto Pop = [&](int i) {
      int x = arr[i];
      int old = cnt[x];
      Sub(old);
      Add(--cnt[x]);
    };

    auto Max = [&]() {
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
  }

  return 0;
}
