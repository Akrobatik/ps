// Title : 서로 다른 수와 쿼리 1
// Link  : https://www.acmicpc.net/problem/14897 
// Time  : 1896 ms
// Memory: 68076 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int arr[1000000], ans[1000000], cnt[1000001];
tup queries[1000000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<int64_t, int> hm;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int64_t x;
    cin >> x;
    if (auto it = hm.find(x); it != hm.end()) {
      arr[i] = it->second;
    } else {
      arr[i] = hm[x] = hm.size();
    }
  }

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
