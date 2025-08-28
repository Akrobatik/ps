// Title : 괄호 문자열과 쿼리
// Link  : https://www.acmicpc.net/problem/17407 
// Time  : 20 ms
// Memory: 4328 KB

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

constexpr int kInf = INT_MAX >> 1;

struct Node {
  Node() : minn(kInf), sum(0) {}
  Node(int v) : minn(v), sum(v) {}

  int minn, sum;
};

struct FOp {
  Node operator()(const Node& lhs, const Node& rhs) const {
    Node res;
    res.minn = min<int>(lhs.minn, lhs.sum + rhs.minn);
    res.sum = lhs.sum + rhs.sum;
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int m;
  cin >> s >> m;
  int n = s.size();

  SegTree<Node, FOp> seg;
  seg.Init(n, Node());
  for (int i = 0; i < n; i++) {
    s[i] ^= 41;
    seg.Set(i, s[i] ? 1 : -1);
  }
  seg.Build();

  int cnt = 0;
  while (m--) {
    int i;
    cin >> i;
    --i;
    s[i] ^= 1;
    seg.Update(i, s[i] ? 1 : -1);
    auto res = seg.Query(0, n - 1);
    cnt += (res.sum == 0 && res.minn >= 0);
  }
  cout << cnt;

  return 0;
}
