// Title : 쿼리와 쿼리
// Link  : https://www.acmicpc.net/problem/17082 
// Time  : 148 ms
// Memory: 6572 KB

#include <bits/stdc++.h>

using namespace std;

// https://github.com/Akrobatik/ps/blob/main/template/segment_tree.cpp
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
  Node operator()(const Node& a, const Node& b) const {
    return max<int>(a, b);
  }
};

constexpr int kInf = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<int> lrr(m), rrr(m);
  for (auto& e : lrr) cin >> e;
  for (auto& e : rrr) cin >> e;
  sort(lrr.begin(), lrr.end());
  sort(rrr.begin(), rrr.end());

  bool ok = true;
  vector<bool> act(n + 1);
  int ml = 0;
  for (int i = 0; i < m; i++) {
    int l = lrr[i], r = rrr[i];
    if (l <= r) {
      for (int j = max<int>(l, ml); j <= r; j++) {
        act[j] = true;
      }
    } else {
      ok = false;
    }
    ml = max<int>(ml, r + 1);
  }

  SegTree<Node, FOp> seg;
  seg.Init(n + 1, -kInf);
  for (int i = 1; i <= n; i++) {
    if (!act[i]) continue;
    seg.Set(i, arr[i]);
  }
  seg.Build();

  while (q--) {
    int a, b;
    cin >> a >> b;
    swap(arr[a], arr[b]);
    if (act[a]) seg.Update(a, arr[a]);
    if (act[b]) seg.Update(b, arr[b]);

    cout << (ok ? seg.Query(1, n) : kInf) << "\n";
  }

  return 0;
}