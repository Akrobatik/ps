// Title : 여우가 정보섬에 올라온 이유
// Link  : https://www.acmicpc.net/problem/17131 
// Time  : 124 ms
// Memory: 6424 KB

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
    return a + b;
  }
};

constexpr int kMod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> arr(n);
  vector<int> memo(n);
  for (int i = 0; i < n; i++) {
    int y, x;
    cin >> x >> y;
    arr[i] = {y, x};
    memo[i] = x;
  }
  sort(arr.begin(), arr.end(), greater<pair<int, int>>());
  sort(memo.begin(), memo.end());
  memo.erase(unique(memo.begin(), memo.end()), memo.end());

  for (auto& [y, x] : arr) {
    x = lower_bound(memo.begin(), memo.end(), x) - memo.begin();
  }

  int m = memo.size();

  SegTree<Node, FOp> seg;
  seg.Init(m, 0);

  int idx = 0;
  int64_t ans = 0;
  for (auto [y, x] : arr) {
    while (idx < n && arr[idx].first > y) {
      auto [yy, xx] = arr[idx++];
      seg.Update(xx, seg.Query(xx) + 1);
    }

    int64_t ls = seg.Query(0, x - 1), rs = seg.Query(x + 1, m - 1);
    ans = (ans + ls * rs) % kMod;
  }
  cout << ans;

  return 0;
}