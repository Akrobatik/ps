// Title : 그룹 부분 문자열과 쿼리
// Link  : https://www.acmicpc.net/problem/34877 
// Time  : 108 ms
// Memory: 11352 KB

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
  Node() : sz(0), h(0), sum(0) {}
  Node(int64_t _sz, int64_t _h, int64_t _sum) : sz(_sz), h(_h), sum(_sum) {}

  int64_t sz, h, sum;
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.sz = b.sz + (b.sum == 0 ? a.sz : 0);
    res.h = max<int64_t>(a.h, b.h);
    res.sum = a.sum + b.sum;
    if (a.sz > 0 && b.sum > 0) res.sum += a.sz * b.h;
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;

  vector<pair<int, int>> qr(q);
  for (auto& [cur, add] : qr) cin >> cur >> add;

  int prv = 0;
  int64_t cnt[2] = {};
  vector<int64_t> memo[2];
  for (auto [cur, add] : qr) {
    if (cur == prv) {
      cnt[cur] += add;
    } else {
      cnt[cur] = add;
    }
    memo[cur].push_back(cnt[cur]);
    memo[prv].push_back(cnt[prv]);
    prv = cur;
  }

  for (int i = 0; i < 2; i++) {
    sort(memo[i].begin(), memo[i].end());
    memo[i].erase(unique(memo[i].begin(), memo[i].end()), memo[i].end());
  }

  auto Get = [&](int i, int64_t x) {
    return lower_bound(memo[i].begin(), memo[i].end(), x) - memo[i].begin();
  };

  SegTree<Node, FOp> seg[2];
  vector<int64_t> sz[2];
  for (int i = 0; i < 2; i++) {
    int nm = memo[i].size();

    sz[i].resize(nm);
    for (int j = 0; j < nm; j++) {
      sz[i][j] = memo[i][j] - (j > 0 ? memo[i][j - 1] : 0);
    }

    seg[i].Init(nm, Node());
    for (int j = 0; j < nm; j++) {
      seg[i].Set(j, Node(sz[i][j], 0, 0));
    }
    seg[i].Build();
  }

  prv = 0;
  cnt[0] = cnt[1] = 0;
  int64_t maxx[2] = {};
  map<int, int64_t> mp[2];

  auto Push = [&](int i, int x, int64_t h) {
    if (h == 0) return;

    auto& m = mp[i];
    auto it = m.lower_bound(x);
    if (it != m.end() && it->second >= h) return;

    seg[i].Update(x, Node(0, h, sz[i][x] * h));

    m[x] = h;
    it = m.find(x);
    while (it != m.begin() && prev(it)->second <= h) {
      auto [xx, hh] = *--it;
      it = m.erase(it);

      seg[i].Update(xx, Node(sz[i][xx], 0, 0));
    }
  };

  for (auto [cur, add] : qr) {
    if (cur == prv) {
      cnt[cur] += add;
    } else {
      cnt[cur] = add;
    }

    int idx = Get(cur, cnt[cur]);
    Push(cur, idx, cnt[cur ^ 1]);

    int64_t sum = 0;
    for (int i = 0; i < 2; i++) {
      int nm = memo[i].size();
      sum += seg[i].Query(0, nm - 1).sum;

      maxx[i] = max<int64_t>(maxx[i], cnt[i]);
      sum += maxx[i];
    }
    cout << sum << "\n";

    prv = cur;
  }

  return 0;
}