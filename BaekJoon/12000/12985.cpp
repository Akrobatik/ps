// Title : 비밀 회선
// Link  : https://www.acmicpc.net/problem/12985 
// Time  : 32 ms
// Memory: 5500 KB

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

using Node = int64_t;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    return a + b;
  }
};

constexpr int kMax = 5e4;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> arr(n);
  for (auto& [v, x] : arr) cin >> v >> x;
  sort(arr.begin(), arr.end());

  SegTree<Node, FOp> fwd, bwd, cnt;
  fwd.Init(kMax + 1, 0);
  bwd.Init(kMax + 1, 0);
  cnt.Init(kMax + 1, 0);

  int64_t ans = 0;
  for (auto [v, x] : arr) {
    int64_t fsum = fwd.Query(0, x - 1);
    int64_t bsum = bwd.Query(x + 1, kMax);
    int64_t fcnt = cnt.Query(0, x - 1);
    int64_t bcnt = cnt.Query(x + 1, kMax);
    ans += (fsum - fcnt * (kMax - x) + bsum - bcnt * x) * v;

    fwd.Update(x, fwd.Query(x) + kMax - x);
    bwd.Update(x, bwd.Query(x) + x);
    cnt.Update(x, cnt.Query(x) + 1);
  }
  cout << ans;

  return 0;
}
