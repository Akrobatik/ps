#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
  void Init(int n) {
    nmax = has_single_bit((uint32_t)n) ? n : (1 << (32 - countl_zero((uint32_t)n)));
    tree.clear(), tree.resize(nmax << 1);
  }

  void Update(int idx, int64_t value) {
    int node = idx + nmax;
    int64_t delta = value - tree[node];
    tree[node] = value;
    while ((node >>= 1)) tree[node] += delta;
  }

  int64_t Query(int l, int r) {
    int64_t res = 0;
    for (l += nmax, r += nmax + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res += tree[l++];
      if (r & 1) res += tree[--r];
    }
    return res;
  }

  int nmax;
  vector<int64_t> tree;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;
  SegmentTree tree;
  tree.Init(n + 1);
  vector<int> walls(m);
  for (int i = 0; i < m; i++) {
    int w, d;
    cin >> w >> d;
    tree.Update(w, d);
    walls[i] = w;
  }
  sort(walls.begin(), walls.end());

  while (q--) {
    int p;
    cin >> p;
    auto l = tree.Query(1, p - 1);
    auto r = tree.Query(p + 1, n);
    if (l < r || (l == r && p - 1 <= n - p)) {
      auto e = lower_bound(walls.begin(), walls.end(), p);
      for (auto it = walls.begin(); it != e; ++it) tree.Update(*it, 0);
      walls.erase(walls.begin(), e);
      cout << l << "\n";
    } else {
      auto b = lower_bound(walls.begin(), walls.end(), p);
      for (auto it = b; it != walls.end(); ++it) tree.Update(*it, 0);
      walls.erase(b, walls.end());
      cout << r << "\n";
    }
  }

  return 0;
}
