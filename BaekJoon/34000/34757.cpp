// Title : 제설 작업
// Link  : https://www.acmicpc.net/problem/34757 
// Time  : 1220 ms
// Memory: 23152 KB

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

using Node = int64_t;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    return a + b;
  }
};

using tup = tuple<int64_t, int64_t, int64_t>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m, q;
  cin >> n >> m >> q;

  vector<int64_t> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<tup> task(m);
  for (auto& [l, r, w] : task) cin >> l >> r >> w;

  vector<int> memo;

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return;
    if (a < b) swap(a, b);
    memo[b] = a;
  };

  vector<int64_t> axr;
  SegTree<Node, FOp> seg;

  auto Init = [&]() {
    memo.resize(n + 2);
    iota(memo.begin(), memo.end(), 0);

    seg.Init(n + 1, 0);
    axr.assign(n + 1, 0);
  };

  auto Build = [&](int st, int en) {
    for (int i = st; i < en; i++) {
      auto [l, r, w] = task[i];

      int64_t rem = w, cur = Find(l);
      while (cur <= r && rem > 0) {
        int64_t cut = min<int64_t>(rem, arr[cur] - axr[cur]);
        rem -= cut;
        if ((axr[cur] += cut) == arr[cur]) Union(cur, cur + 1);
        seg.Update(cur, seg.Query(cur) + cut);
        cur = Find(cur + 1);
      }
    }
  };

  vector<tup> qr(q);
  for (auto& [l, r, t] : qr) cin >> l >> r >> t;

  vector<pair<int, int>> cands;
  vector<int> lo(q, 0), hi(q, m + 1);
  for (;;) {
    cands.clear();
    for (int i = 0; i < q; i++) {
      if (lo[i] + 1 < hi[i]) {
        int mid = (lo[i] + hi[i]) >> 1;
        cands.push_back({mid, i});
      }
    }
    if (cands.empty()) break;
    sort(cands.begin(), cands.end());

    Init();

    int prv = 0, idx = 0, nc = cands.size();
    while (idx < nc) {
      int val = cands[idx].first, nxt = idx;
      while (nxt < nc && cands[nxt].first == val) ++nxt;
      Build(prv, val);

      for (int i = idx; i < nxt; i++) {
        int qi = cands[i].second;
        auto [l, r, t] = qr[qi];
        int64_t sum = seg.Query(l, r);
        if (sum >= t) {
          hi[qi] = val;
        } else {
          lo[qi] = val;
        }
      }

      prv = val, idx = nxt;
    }
  }

  for (int i = 0; i < q; i++) {
    cout << (hi[i] <= m ? hi[i] : -1) << "\n";
  }

  return 0;
}