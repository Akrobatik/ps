// Title : 히스토그램과 쿼리
// Link  : https://www.acmicpc.net/problem/34101 
// Time  : 660 ms
// Memory: 84476 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

constexpr int kMax = 1 << 20;
int tree[kMax << 1];

void Inc(int idx) {
  int node = idx + kMax;
  while (node) ++tree[node], node >>= 1;
}

int Query(int l, int r) {
  int res = 0;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += tree[l++];
    if (r & 1) res += tree[--r];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];

  vector<vector<int>> memo(n + 1);
  vector<int> stk;
  for (int i = 1; i <= n; i++) {
    int x = arr[i];
    while (!stk.empty() && arr[stk.back()] > x) stk.pop_back();

    if (!stk.empty() && arr[stk.back()] == x) {
      memo[stk.back()].push_back(i);
    } else {
      memo[0].push_back(i);
    }

    while (!stk.empty() && arr[stk.back()] == x) stk.pop_back();
    stk.push_back(i);
  }

  int q;
  cin >> q;
  vector<tup> queries(q);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    queries[i] = {l, r, i};
  }
  sort(queries.begin(), queries.end(), [&](const tup& lhs, const tup& rhs) {
    auto [ll, lr, li] = lhs;
    auto [rl, rr, ri] = rhs;
    return ll < rl;
  });

  vector<int> ans(q);
  int idx = 0;
  for (auto [l, r, i] : queries) {
    while (idx < l) {
      for (auto x : memo[idx]) {
        Inc(x);
      }
      ++idx;
    }
    ans[i] = Query(l, r);
  }

  for (auto e : ans) cout << e << "\n";

  return 0;
}
