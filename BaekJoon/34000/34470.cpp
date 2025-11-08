// Title : To-Do List
// Link  : https://www.acmicpc.net/problem/34470 
// Time  : 604 ms
// Memory: 67312 KB

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

// using Node = int64_t;
struct Node {
  Node() : st(0), en(0) {}
  Node(int64_t s, int64_t t) : st(t > 0 ? s : 0), en(t > 0 ? s + t : 0) {}

  int64_t st, en;
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    if (a.en <= b.st) {
      int64_t dt = b.st - a.en;
      res.st = a.st + dt;
      res.en = b.en;
    } else {
      int64_t dt = a.en - b.st;
      res.st = a.st;
      res.en = b.en + dt;
    }
    return res;
  }
};

constexpr int kMax = 1e6 + 3;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int64_t ans = 0;
  SegTree<Node, FOp> seg;
  seg.Init(kMax, Node());
  vector<pair<int64_t, int64_t>> old;
  vector<int64_t> arr(kMax);
  while (n--) {
    char cmd;
    cin >> cmd;
    if (cmd == 'A') {
      int64_t s, t;
      cin >> s >> t;
      s = (s + ans) % kMax;
      t = (t + ans) % kMax;
      old.push_back({s, t});
      arr[s] += t;
      seg.Update(s, Node(s, arr[s]));
    } else {
      int64_t i;
      cin >> i;
      i = (i + ans) % kMax;
      auto [s, t] = old[i - 1];
      arr[s] -= t;
      seg.Update(s, Node(s, arr[s]));
    }
    ans = max<int64_t>(seg.Query(0, kMax - 1).en - 1, 0);
    cout << ans << "\n";
  }

  return 0;
}