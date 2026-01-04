// Title : 수열과 쿼리 1.5
// Link  : https://www.acmicpc.net/problem/17410 
// Time  : 460 ms
// Memory: 15348 KB

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int bs = 1 << 10;
  int s = (n + bs - 1) / bs;
  vector<SegTree<Node, FOp>> bkts(s);
  for (auto& seg : bkts) seg.Init(10001, 0);
  for (int i = 0; i < n; i++) {
    auto& seg = bkts[i / bs];
    seg.Set(arr[i], seg.Query(arr[i]) + 1);
  }
  for (auto& seg : bkts) seg.Build();

  int m;
  cin >> m;
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int i, v;
      cin >> i >> v, --i;

      auto& seg = bkts[i / bs];
      seg.Update(arr[i], seg.Query(arr[i]) - 1);
      seg.Update(v, seg.Query(v) + 1);
      arr[i] = v;
    } else {
      int i, j, k;
      cin >> i >> j >> k, --i, --j;

      int cnt = 0, lb = i / bs, ub = j / bs;
      for (int b = lb; b <= ub; b++) {
        int st = b * bs, en = st + bs - 1;
        if (i <= st && en <= j) {
          cnt += bkts[b].Query(k + 1, 10000);
        } else {
          st = max<int>(st, i), en = min<int>(en, j);
          for (int l = st; l <= en; l++) {
            cnt += (arr[l] > k);
          }
        }
      }
      cout << cnt << "\n";
    }
  }

  return 0;
}