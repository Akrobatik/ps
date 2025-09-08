// Title : 플러스 마이너스 합 최대
// Link  : https://www.acmicpc.net/problem/34239 
// Time  : 56 ms
// Memory: 19196 KB

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

constexpr int64_t kInf = 1e18;

struct Node {
  Node() : maxx(-kInf), sum(0) {}
  Node(int64_t v) : maxx(v), sum(v) {}

  int64_t maxx, sum;
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.maxx = max<int64_t>(a.maxx, a.sum + b.maxx);
    res.sum = a.sum + b.sum;
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  SegTree<Node, FOp> s1, s2;
  s1.Init(n, Node());
  s2.Init(n, Node());
  for (int i = 0, s = 1; i < n; i++, s *= -1) {
    s1.Set(i, arr[i] * s);
    s2.Set(i, arr[i] * -s);
  }
  s1.Build();
  s2.Build();

  int64_t maxx = -kInf;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      maxx = max<int64_t>(maxx, s2.Query(i, n - 1).maxx);
    } else {
      maxx = max<int64_t>(maxx, s1.Query(i, n - 1).maxx);
    }
  }
  cout << maxx;

  return 0;
}