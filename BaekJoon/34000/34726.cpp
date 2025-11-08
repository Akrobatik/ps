// Title : DRS
// Link  : https://www.acmicpc.net/problem/34726 
// Time  : 316 ms
// Memory: 143240 KB

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;

  vector<int> cnt(t);
  vector<vector<string>> memo(t);
  int64_t acc = 0;
  for (int i = 0; i < n; i++) {
    string s;
    int x;
    cin >> s >> x;
    acc -= x;
    int p = acc % t;
    if (p < 0) p += t;
    ++cnt[p];
    memo[p].push_back(s);
  }

  SegTree<Node, FOp> seg;
  seg.Init(t, 0);
  for (int i = 0; i < t; i++) {
    seg.Set(i, cnt[i]);
  }
  seg.Build();

  vector<string> ans;
  for (int i = 0; i < t; i++) {
    if (cnt[i] == 0) continue;

    bool ok = false;
    int l = i + 1, r = i + 1000;
    if (l >= t) {
      l -= t, r -= t;
      ok = (seg.Query(l, r) > 0);
    } else if (r >= t) {
      ok = (seg.Query(l, t - 1) > 0 || seg.Query(0, r - t) > 0);
    } else {
      ok = (seg.Query(l, r) > 0);
    }

    if (ok) {
      for (auto& s : memo[i]) ans.push_back(s);
    }
  }
  sort(ans.begin(), ans.end());

  if (ans.empty()) {
    cout << "-1";
    return 0;
  }
  for (auto& s : ans) cout << s << " ";

  return 0;
}