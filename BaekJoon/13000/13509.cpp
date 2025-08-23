// Title : 가장 가까운 두 점 2
// Link  : https://www.acmicpc.net/problem/13509 
// Time  : 300 ms
// Memory: 8780 KB

#include <bits/stdc++.h>

using namespace std;

template <typename V, typename OP>
  requires requires(V a, V b) {
    { OP{}(a, b) } -> convertible_to<V>;
  }
struct SegTree {
  void Init(int n, const V& ival) {
    nmax = bit_ceil((uint32_t)n);
    iv = ival;
    tree.assign(nmax << 1, iv);
  }

  void Set(int idx, const V& val) {
    tree[idx + nmax] = val;
  }

  void Build() {
    for (int i = nmax - 1; i > 0; i--) {
      tree[i] = OP{}(tree[i << 1], tree[i << 1 | 1]);
    }
  }

  void Update(int idx, const V& val) {
    int node = idx + nmax;
    tree[node] = val;
    while (node >>= 1) {
      tree[node] = OP{}(tree[node << 1], tree[node << 1 | 1]);
    }
  }

  V Query(int idx) const {
    return tree[idx + nmax];
  }

  V Query(int l, int r) const {
    V lv = iv, rv = iv;
    for (l += nmax, r += nmax + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lv = OP{}(lv, tree[l++]);
      if (r & 1) rv = OP{}(tree[--r], rv);
    }
    return OP{}(lv, rv);
  }

 private:
  int nmax;
  V iv;
  vector<V> tree;
};

using Node = int;

struct FOp {
  Node operator()(const Node& lhs, const Node& rhs) const {
    return max<int>(lhs, rhs);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  SegTree<Node, FOp> seg;

  int n;
  cin >> n;

  vector<pair<int, int>> arr(n);
  vector<int> xrr(n), yrr(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    arr[i] = {x, y};
    xrr[i] = x, yrr[i] = y;
  }

  sort(xrr.begin(), xrr.end());
  xrr.erase(unique(xrr.begin(), xrr.end()), xrr.end());
  sort(yrr.begin(), yrr.end());
  yrr.erase(unique(yrr.begin(), yrr.end()), yrr.end());

  for (auto& [x, y] : arr) {
    x = lower_bound(xrr.begin(), xrr.end(), x) - xrr.begin();
    y = lower_bound(yrr.begin(), yrr.end(), y) - yrr.begin();
  }

  vector<int> ans(n, INT_MAX), ids(n);
  iota(ids.begin(), ids.end(), 0);

  int nx = xrr.size(), ny = yrr.size();
  for (int dir = 0; dir < 4; dir++) {
    auto Get = [&](int i) -> pair<int, int> {
      auto [x, y] = arr[i];
      x = xrr[x], y = yrr[y];
      if (dir & 1) x = -x;
      if (dir & 2) y = -y;
      return {x, y};
    };

    auto GetR = [&](int i) -> pair<int, int> {
      auto [x, y] = arr[i];
      if (dir & 1) x = nx - x - 1;
      if (dir & 2) y = ny - y - 1;
      return {x, y};
    };

    sort(ids.begin(), ids.end(), [&](int lhs, int rhs) {
      auto [lx, ly] = GetR(lhs);
      auto [rx, ry] = GetR(rhs);
      return lx < rx || (lx == rx && ly < ry);
    });

    seg.Init(ny, INT_MIN >> 1);
    for (auto id : ids) {
      auto [x, y] = Get(id);
      auto [rx, ry] = GetR(id);
      ans[id] = min<int>(ans[id], x + y - seg.Query(0, ry));
      seg.Update(ry, x + y);
    }
  }

  for (auto e : ans) cout << e << "\n";

  return 0;
}