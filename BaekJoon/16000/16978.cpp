// Title : 수열과 쿼리 22
// Link  : https://www.acmicpc.net/problem/16978 
// Time  : 52 ms
// Memory: 6508 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 17;

int64_t tree[kMax << 1];

int64_t Query(int l, int r) {
  int64_t res = 0;
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
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int node = i + kMax;
    while (node) tree[node] += x, node >>= 1;
  }

  int m;
  cin >> m;
  vector<pair<int, int>> q1;
  vector<tuple<int, int, int, int>> q2;

  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i, v;
      cin >> i >> v;
      q1.push_back({i - 1, v});
    } else {
      int k, i, j;
      cin >> k >> i >> j;
      q2.push_back({k, i - 1, j - 1, q2.size()});
    }
  }
  sort(q2.begin(), q2.end());

  vector<int64_t> ans(q2.size());

  int idx = 0;
  auto it = q2.begin();
  while (it != q2.end()) {
    auto [k, i, j, qi] = *it++;
    while (idx < k) {
      auto [ii, vv] = q1[idx++];
      int node = ii + kMax;
      int64_t delta = vv - tree[node];
      while (node) tree[node] += delta, node >>= 1;
    }
    ans[qi] = Query(i, j);
  }

  for (auto e : ans) cout << e << "\n";

  return 0;
}
