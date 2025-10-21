// Title : Zečevi
// Link  : https://www.acmicpc.net/problem/34583 
// Time  : 1736 ms
// Memory: 30944 KB

#pragma GCC optimize("O3")

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
  Node() : sum(0), cnt(0) {}
  Node(int64_t s, int64_t c) : sum(s), cnt(c) {}

  int64_t sum, cnt;
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.sum = a.sum + b.sum;
    res.cnt = a.cnt + b.cnt;
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<pair<int64_t, int64_t>> arr(n), bxr(m);
  for (auto& [a, b] : arr) cin >> a >> b;
  for (auto& [a, b] : bxr) cin >> a >> b;
  sort(arr.begin(), arr.end());
  sort(bxr.begin(), bxr.end());

  int idx = 0;
  vector<pair<int64_t, int64_t>> brr;
  while (idx < m) {
    int pos = bxr[idx].first, nxt = idx;
    int64_t sum = 0;
    while (nxt < m && bxr[nxt].first == pos) sum += bxr[nxt++].second;
    brr.push_back({pos, sum});
    idx = nxt;
  }

  SegTree<Node, FOp> seg;

  vector<int64_t> memo;

  auto Idx = [&](int64_t x) {
    return lower_bound(memo.begin(), memo.end(), x) - memo.begin();
  };

  auto Check = [&](int64_t x) -> bool {
    memo.clear();
    for (auto [a, b] : arr) memo.push_back(a + b), memo.push_back(a + x);
    for (auto [a, b] : brr) memo.push_back(a);
    sort(memo.begin(), memo.end());
    memo.erase(unique(memo.begin(), memo.end()), memo.end());

    bxr.clear();
    for (auto [a, b] : arr)
      if (b < x) bxr.push_back({Idx(a + x), -1});
    for (auto [a, b] : brr) bxr.push_back({Idx(a), b});
    sort(bxr.begin(), bxr.end());

    int nm = memo.size();
    seg.Init(nm, Node());

    int64_t add = 0, cap = 0;
    int idx = 0, prv = 0;
    for (auto [a, b] : bxr) {
      while (idx < n && arr[idx].first <= memo[a]) {
        auto [aa, bb] = arr[idx++];
        if (bb >= x) continue;

        int pos = Idx(aa + bb);
        auto res = seg.Query(pos);
        seg.Update(pos, Node(res.sum + aa + bb, res.cnt + 1));
        cap += x - bb;
      }

      auto res = seg.Query(prv, a - 1);
      int64_t req = memo[a] * res.cnt - res.sum;
      if (add < req) return false;
      add -= req, cap -= req;

      {
        auto r = seg.Query(a);
        seg.Update(a, Node(r.sum + memo[a] * res.cnt, r.cnt + res.cnt));
      }

      if (b < 0) {
        auto r = seg.Query(a);
        seg.Update(a, Node(r.sum - memo[a], r.cnt - 1));
      } else {
        add = min<int64_t>(add + b, cap);
      }
      prv = a;
    }
    return true;
  };

  int64_t s = 0;
  for (auto [a, b] : arr) s += b;
  for (auto [a, b] : brr) s += b;

  int64_t limit = INT64_MAX;
  idx = 0;
  for (auto [a, b] : arr) {
    while (idx < brr.size() && brr[idx].first < a) ++idx;
    if (idx == brr.size() || a + b < brr[idx].first) limit = min<int64_t>(limit, b);
  }

  int64_t lo = 0, hi = min<int64_t>(s / n, limit) + 1;
  while (lo + 1 < hi) {
    int64_t mid = (lo + hi) >> 1;
    if (Check(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << lo;

  return 0;
}