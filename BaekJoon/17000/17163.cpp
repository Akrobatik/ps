// Title : 가희의 수열놀이 (Large)
// Link  : https://www.acmicpc.net/problem/17163 
// Time  : 444 ms
// Memory: 71184 KB

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

  // private:
  int nmax;
  V iv;
  vector<V> tree;
};

using Node = int;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    return min<int>(a, b);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  if (n <= m) {
    for (int i = 0; i < n; i++) {
      int cmd;
      cin >> cmd;
      if (cmd == 3) cout << "-1\n";
      if (cmd == 1) cin >> cmd;
    }
    return 0;
  }

  vector<vector<int>> memo(m, {-1});
  vector<int> arr;

  SegTree<Node, FOp> seg;
  seg.Init(m, INT_MAX);
  for (int i = 0; i < m; i++) seg.Set(i, -1);
  seg.Build();

  for (int i = 0; i < n; i++) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int x;
      cin >> x;
      x %= m;
      int idx = arr.size();
      arr.push_back(x);
      memo[x].push_back(idx);
      seg.Update(x, idx);
    } else if (cmd == 2) {
      if (arr.empty()) continue;
      int x = arr.back();
      arr.pop_back();
      memo[x].pop_back();
      seg.Update(x, memo[x].back());
    } else {
      int sz = arr.size();
      int minn = seg.tree[1];
      cout << (minn != -1 ? sz - minn : -1) << "\n";
    }
  }

  return 0;
}
