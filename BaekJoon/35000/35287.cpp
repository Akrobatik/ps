// Title : MC 히페리온
// Link  : https://www.acmicpc.net/problem/35287 
// Time  : 316 ms
// Memory: 338016 KB

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
  Node() : nxt{}, minn(INT_MAX), maxx(INT_MIN), id(0) {}

  int nxt[26];
  int minn, maxx, id;
};

SegTree<int, plus<int>> seg;
int nidx;
Node nodes[2000001];

void Insert(const string& s, int id) {
  int n = s.size();
  Node* node = nodes;
  for (int i = 0; i < n; i++) {
    int x = s[i] - 'a';
    if (node->nxt[x] == 0) node->nxt[x] = ++nidx;
    node = nodes + node->nxt[x];
  }
  node->id = id;
}

int64_t Query(const string& s) {
  int64_t n = s.size();
  Node* node = nodes;
  for (int i = 0; i < n; i++) {
    int x = s[i] - 'a';
    if (node->nxt[x] == 0) return 0;
    node = nodes + node->nxt[x];
  }
  return n * seg.Query(node->minn, node->maxx);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    Insert(s, i);
  }

  int aidx = 0;
  vector<int> arr(n + 1);

  [&](this auto&& self, int idx) -> pair<int, int> {
    Node* node = nodes + idx;
    int minn = INT_MAX, maxx = INT_MIN;
    if (node->id) {
      arr[node->id] = ++aidx;
      minn = min<int>(minn, aidx);
      maxx = max<int>(maxx, aidx);
    }

    for (int i = 0; i < 26; i++) {
      if (node->nxt[i] == 0) continue;
      auto [mn, mx] = self(node->nxt[i]);
      minn = min<int>(minn, mn);
      maxx = max<int>(maxx, mx);
    }
    node->minn = minn, node->maxx = maxx;
    return {minn, maxx};
  }(0);

  seg.Init(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    seg.Set(arr[i], x);
  }
  seg.Build();

  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int x, y;
      cin >> x >> y;
      seg.Update(arr[x], y);
    } else {
      string s;
      cin >> s;
      reverse(s.begin(), s.end());
      cout << Query(s) << "\n";
    }
  }

  return 0;
}