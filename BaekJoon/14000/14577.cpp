// Title : 일기예보
// Link  : https://www.acmicpc.net/problem/14577 
// Time  : 104 ms
// Memory: 9376 KB

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

  int kth(int k) {
    int node = 1;
    while (node < nmax) {
      node <<= 1;
      if (tree[node] < k) k -= tree[node++];
    }
    return node - nmax;
  }

 private:
  int nmax;
  V iv;
  vector<V> tree;
};

using Node = int;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    return a + b;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int64_t> arr(n + 1), axr;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    axr.push_back(arr[i]);
  }

  vector<tuple<int, int64_t, int64_t>> qr(m);
  for (auto& [cmd, a, b] : qr) {
    cin >> cmd >> a;
    if (cmd != 4) cin >> b;
  }

  for (auto [cmd, a, b] : qr) {
    if (cmd <= 2) {
      arr[a] += b * (cmd == 1 ? 1 : -1);
      axr.push_back(arr[a]);
    } else if (cmd == 3) {
      axr.push_back(a);
      axr.push_back(b);
    }
  }
  for (auto [cmd, a, b] : qr) {
    if (cmd >= 3) continue;
    arr[a] += b * (cmd == 1 ? -1 : 1);
  }

  sort(axr.begin(), axr.end());
  axr.erase(unique(axr.begin(), axr.end()), axr.end());

  auto Get = [&](int64_t x) -> int {
    return lower_bound(axr.begin(), axr.end(), x) - axr.begin();
  };

  int na = axr.size();
  SegTree<Node, FOp> seg;
  seg.Init(na, 0);
  for (int i = 1; i <= n; i++) {
    int idx = Get(arr[i]);
    seg.Update(idx, seg.Query(idx) + 1);
  }

  for (auto [cmd, a, b] : qr) {
    switch (cmd) {
      case 1: {
        int old = Get(arr[a]);
        arr[a] += b;
        int cur = Get(arr[a]);

        seg.Update(old, seg.Query(old) - 1);
        seg.Update(cur, seg.Query(cur) + 1);
      } break;

      case 2: {
        int old = Get(arr[a]);
        arr[a] -= b;
        int cur = Get(arr[a]);

        seg.Update(old, seg.Query(old) - 1);
        seg.Update(cur, seg.Query(cur) + 1);
      } break;

      case 3: {
        cout << seg.Query(Get(a), Get(b)) << "\n";
      } break;

      case 4: {
        cout << axr[seg.kth(n - a + 1)] << "\n";
      } break;
    }
  }

  return 0;
}