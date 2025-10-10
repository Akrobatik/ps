// Title : 추출하는 폴도 바리스타입니다
// Link  : https://www.acmicpc.net/problem/15648 
// Time  : 104 ms
// Memory: 8064 KB

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

constexpr int kMax = 5e5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, d;
  cin >> n >> k >> d;

  SegTree<Node, FOp> seg;
  seg.Init(kMax + 1, 0);

  vector<int> memo(k);
  while (n--) {
    int x;
    cin >> x;
    int lb = max<int>(x - d, 1);
    int ub = min<int>(x + d, kMax);
    int r = x % k;
    int cur = max<int>(memo[r], seg.Query(lb, ub)) + 1;
    memo[r] = cur;
    seg.Update(x, cur);
  }
  cout << seg.Query(1, kMax);

  return 0;
}