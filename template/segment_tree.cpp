#include <bits/stdc++.h>

using namespace std;

template <typename V, typename OP, auto IV>
  requires requires(V a, V b) {
    { OP{}(a, b) } -> convertible_to<V>;
    requires(is_invocable_r_v<V, decltype(IV)> || convertible_to<decltype(IV), V>);
  }
struct SegTree {
  void Init(int n) {
    nmax = bit_ceil(static_cast<unsigned>(n));
    tree.assign(nmax << 1, IValue());
  }

  void Set(int idx, const V& val) {
    tree[idx + nmax] = val;
  }

  void Build() {
    for (int i = nmax - 1; i > 0; --i) {
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

  template <typename T, typename F>
    requires requires(V a, T b) {
      { F{}(a, b) } -> convertible_to<V>;
    }
  void Update(int idx, const T& delta, F func) {
    int node = idx + nmax;
    tree[node] = func(tree[node], delta);
    while (node >>= 1) {
      tree[node] = OP{}(tree[node << 1], tree[node << 1 | 1]);
    }
  }

  V Query(int l, int r) const {
    V lv = IValue(), rv = IValue();
    for (l += nmax, r += nmax + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lv = OP{}(lv, tree[l++]);
      if (r & 1) rv = OP{}(tree[--r], rv);
    }
    return OP{}(lv, rv);
  }

  int nmax;
  vector<V> tree;

 private:
  static constexpr V IValue() {
    if constexpr (is_invocable_r_v<V, decltype(IV)>) {
      return invoke(IV);
    } else {
      return IV;
    }
  }
};