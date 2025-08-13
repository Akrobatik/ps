// Title : 수열과 쿼리 11
// Link  : https://www.acmicpc.net/problem/13704 
// Time  : 188 ms
// Memory: 8484 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

constexpr int kMax = 1 << 20;

int main() {

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  int n, k;

  cin >> n >> k;

  vector<int> arr(n + 1);

  for (int i = 1; i <= n; i++) {

    int x;

    cin >> x;

    arr[i] = arr[i - 1] ^ x;

  }

  int m;

  cin >> m;

  vector<tup> queries(m);

  for (int i = 0; i < m; i++) {

    int l, r;

    cin >> l >> r;

    queries[i] = {l - 1, r, i};

  }

  int s = sqrt(n) + 1;

  sort(queries.begin(), queries.end(), [&](const tup& lhs, const tup& rhs) {

    auto [ll, lr, lq] = lhs;

    auto [rl, rr, rq] = rhs;

    int ls = ll / s, rs = rl / s;

    return ls < rs || (ls == rs && lr < rr);

  });

  int64_t sum = 0;

  vector<int> freq(kMax);

  auto Push = [&](int i) {

    int x = arr[i];

    sum += freq[x ^ k];

    ++freq[x];

  };

  auto Pop = [&](int i) {

    int x = arr[i];

    --freq[x];

    sum -= freq[x ^ k];

  };

  vector<int64_t> ans(m);

  auto [l, r, q] = queries[0];

  for (int i = l; i <= r; i++) {

    Push(i);

  }

  ans[q] = sum;

  for (int i = 1; i < m; i++) {

    auto [ll, rr, qq] = queries[i];

    while (ll < l) Push(--l);

    while (rr > r) Push(++r);

    while (ll > l) Pop(l++);

    while (rr < r) Pop(r--);

    ans[qq] = sum;

  }

  for (auto e : ans) cout << e << "\n";

  return 0;

}