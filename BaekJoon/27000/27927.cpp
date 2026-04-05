// Title : 벚꽃 엔딩
// Link  : https://www.acmicpc.net/problem/27927 
// Time  : 136 ms
// Memory: 18948 KB

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

struct Node {
  Node() : len(0), fwd(0), bwd(0), maxx(0) {}
  Node(int x) : len(1), fwd(x), bwd(x), maxx(x) {}
  int len, fwd, bwd, maxx;
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    if (a.len == 0) return b;
    if (b.len == 0) return a;

    Node res;
    res.len = a.len + b.len;
    res.fwd = a.fwd + (a.fwd == a.len ? b.fwd : 0);
    res.bwd = b.bwd + (b.bwd == b.len ? a.bwd : 0);
    res.maxx = max<int>({a.maxx, b.maxx, a.bwd + b.fwd});
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> arr(n);
  for (auto& [a, b] : arr) cin >> a >> b, ++b;

  vector<int> memo{m + 1};
  for (auto [a, b] : arr) memo.push_back(a), memo.push_back(b);
  sort(memo.begin(), memo.end());
  memo.erase(unique(memo.begin(), memo.end()), memo.end());

  auto Idx = [&](int x) {
    return lower_bound(memo.begin(), memo.end(), x) - memo.begin();
  };

  for (auto& [a, b] : arr) a = Idx(a), b = Idx(b);

  m = memo.size();

  vector<vector<pair<int, int>>> cands(m);
  for (int i = 0; i < n; i++) {
    auto [a, b] = arr[i];
    cands[a].push_back({i, 1});
    cands[b].push_back({i, 0});
  }

  SegTree<Node, FOp> seg;
  seg.Init(n, Node());
  for (int i = 0; i < n; i++) {
    seg.Set(i, Node(0));
  }
  seg.Build();

  int mv = 0, mc = 0;
  for (int i = 0; i + 1 < m; i++) {
    for (auto [a, b] : cands[i]) {
      seg.Update(a, Node(b));
    }

    int cur = seg.Query(0, n - 1).maxx;
    int cnt = memo[i + 1] - memo[i];
    if (mv < cur) {
      mv = cur, mc = cnt;
    } else if (mv == cur) {
      mc += cnt;
    }
  }
  cout << mv << " " << mc;

  return 0;
}