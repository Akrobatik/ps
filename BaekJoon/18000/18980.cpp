// Title : Distinct Values
// Link  : https://www.acmicpc.net/problem/18980 
// Time  : 232 ms
// Memory: 4428 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int, int>;

tup Split(int l1, int r1, int l2, int r2) {
  int ll = 0, lr = -1, rl = 0, rr = -1;
  if (l1 < l2) ll = l1, lr = min<int>(r1, l2 - 1);
  if (r2 + 1 <= r1) ll = max<int>(ll, r2 + 1), rr = r1;
  if (l2 < l1) rl = l2, rr = min<int>(r2, l1 - 1);
  if (r1 + 1 <= r2) rl = max<int>(l2, r1 + 1), rr = r2;
  return {ll, lr, rl, rr};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr;
  vector<pair<int, int>> lr;

  vector<int> tree;
  int nmax;

  auto Update = [&](int idx, int x) {
    int node = idx + nmax;
    tree[node] = x;
    while (node >>= 1) tree[node] = (tree[node << 1] | tree[(node << 1) + 1]);
  };

  auto Query = [&]() {
    int node = 1;
    while (node < nmax) {
      if (tree[node << 1]) {
        node <<= 1;
      } else {
        node = (node << 1) + 1;
      }
    }
    return node - nmax;
  };

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    arr.assign(n, 1);
    lr.resize(m);
    for (auto& [l, r] : lr) cin >> l >> r, --l, --r;
    sort(lr.begin(), lr.end());

    nmax = has_single_bit((uint32_t)n + 1) ? n + 1 : (1 << (32 - countl_zero((uint32_t)n + 1)));
    tree.assign(nmax << 1, 0);
    for (int i = 1; i <= n; i++) {
      tree[i + nmax] = 1;
    }
    for (int i = nmax - 1; i > 0; i--) {
      tree[i] = (tree[i << 1] | tree[(i << 1) + 1]);
    }

    int pl = -1, pr = -2;
    for (auto [l, r] : lr) {
      if (r <= pr) continue;
      auto [ll, lr, rl, rr] = Split(pl, pr, l, r);
      for (int i = ll; i <= lr; i++) Update(arr[i], 1);
      for (int i = rl; i <= rr; i++) {
        int x = Query();
        arr[i] = x;
        Update(x, 0);
      }
      pl = l, pr = r;
    }
    for (auto e : arr) cout << e << " ";
    cout << "\n";
  }

  return 0;
}
