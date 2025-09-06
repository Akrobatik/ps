// Title : 힝스티비와 쿼리
// Link  : https://www.acmicpc.net/problem/34243 
// Time  : 156 ms
// Memory: 7928 KB

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

  string s;
  cin >> s;
  int n = s.size();

  auto Calc = [&](int a, int b, int c, int l, int r) {
    if (min<int>({a, b, c}) < l || max<int>({a, b, c}) >= r) return 0;
    if (s[a] == '+' && s[b] == '^' && s[c] == '+') return 1;
    if (s[a] == '-' && s[b] == '^' && s[c] == '-') return -1;
    return 0;
  };

  vector<int> fwd(n + 1);
  for (int i = 2; i < n; i++) {
    fwd[i + 1] = fwd[i] + Calc(i - 2, i - 1, i, 0, n);
  }

  SegTree<Node, FOp> seg;
  seg.Init(n + 1, 0);
  for (int i = 0; i < n; i++) {
    int old = 0;
    for (int j = -1; j <= 1; j++) {
      old += Calc(i + j - 1, i + j, i + j + 1, 0, n);
    }

    int cur = Calc(i - 2, i - 1, i + 1, 0, n) + Calc(i - 1, i + 1, i + 2, 0, n);
    seg.Set(i + 1, cur - old);
  }
  seg.Build();

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l + 2 > r) {
      cout << "0\n";
      continue;
    }
    
    int maxx = seg.Query(l + 2, r - 2);
    for (auto i : {l - 1, l, r - 2, r - 1}) {
      int old = 0;
      for (int j = -1; j <= 1; j++) {
        old += Calc(i + j - 1, i + j, i + j + 1, l - 1, r);
      }

      int cur = Calc(i - 2, i - 1, i + 1, l - 1, r) + Calc(i - 1, i + 1, i + 2, l - 1, r);
      maxx = max<int>(maxx, cur - old);
    }
    cout << fwd[r] - fwd[l + 1] + maxx << "\n";
  }

  return 0;
}
