// Title : 수열과 쿼리 2.8e13
// Link  : https://www.acmicpc.net/problem/35435 
// Time  : 564 ms
// Memory: 100336 KB

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

constexpr int64_t kInf = 1e18;

struct Node {
  Node() : s1(0), s2(0), ps1(0), ps2(0), pc(0), pv{kInf, kInf}, ms1(0), ms2(0), mc(0), mv{-kInf, -kInf} {}
  Node(int64_t x) : Node() {
    s1 = x, s2 = x * x;
    if (x >= 0) {
      ps1 = x;
      ps2 = x * x;
      pc = 1;
      pv[0] = x;
    }
    if (x <= 0) {
      ms1 = x;
      ms2 = x * x;
      mc = 1;
      mv[0] = x;
    }
  }

  int64_t s1, s2;
  int64_t ps1, ps2, pc, pv[2];
  int64_t ms1, ms2, mc, mv[2];
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.s1 = a.s1 + b.s1;
    res.s2 = a.s2 + b.s2;
    res.ps1 = a.ps1 + b.ps1;
    res.ps2 = a.ps2 + b.ps2;
    res.pc = a.pc + b.pc;
    res.ms1 = a.ms1 + b.ms1;
    res.ms2 = a.ms2 + b.ms2;
    res.mc = a.mc + b.mc;

    int64_t pv[4] = {a.pv[0], a.pv[1], b.pv[0], b.pv[1]};
    sort(pv, pv + 4);

    int64_t mv[4] = {a.mv[0], a.mv[1], b.mv[0], b.mv[1]};
    sort(mv, mv + 4, greater<int64_t>());

    for (int i = 0; i < 2; i++) {
      res.pv[i] = pv[i];
      res.mv[i] = mv[i];
    }

    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  SegTree<Node, FOp> seg;
  seg.Init(n + 1, Node());
  for (int i = 1; i <= n; i++) {
    int64_t x;
    cin >> x;
    seg.Set(i, Node(x));
  }
  seg.Build();

  int m;
  cin >> m;
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int i, v;
      cin >> i >> v;
      seg.Update(i, Node(v));
    } else {
      int l, r, k;
      cin >> l >> r >> k;

      auto res = seg.Query(l, r);
      int64_t ans = -kInf;
      if (k == 1) {
        ans = (res.s1 * res.s1 - res.s2) / 2;
      } else if (k == 2) {
        if (res.pc == 0) {
          int64_t s1 = res.ms1 - res.mv[0];
          int64_t s2 = res.ms2 - res.mv[0] * res.mv[0];
          ans = (s1 * s1 - s2) / 2;
        } else if (res.mc == 0) {
          int64_t s1 = res.ps1 - res.pv[0];
          int64_t s2 = res.ps2 - res.pv[0] * res.pv[0];
          ans = (s1 * s1 - s2) / 2;
        } else {
          ans = (res.ps1 * res.ps1 - res.ps2) / 2 +
                (res.ms1 * res.ms1 - res.ms2) / 2;
        }
      } else {
        int64_t zc = res.pc + res.mc - (r - l + 1);
        if (zc >= 2) {
          ans = (res.ps1 * res.ps1 - res.ps2) / 2 +
                (res.ms1 * res.ms1 - res.ms2) / 2;
        } else if (zc == 1) {
          int64_t pc = res.pc - zc, mc = res.mc - zc;
          if (pc > 0 && mc > 0) {
            ans = (res.ps1 * res.ps1 - res.ps2) / 2 +
                  (res.ms1 * res.ms1 - res.ms2) / 2;
          } else if (pc > 0) {
            int64_t s1 = res.ps1 - res.pv[1];
            int64_t s2 = res.ps2 - res.pv[1] * res.pv[1];
            ans = (s1 * s1 - s2) / 2;
          } else if (mc > 0) {
            int64_t s1 = res.ms1 - res.mv[1];
            int64_t s2 = res.ms2 - res.mv[1] * res.mv[1];
            ans = (s1 * s1 - s2) / 2;
          } else {
            ans = 0;
          }
        } else {
          if (res.pc > 0 && res.mc > 0) {
            pair<int, int> prs[2] = {{1, 0}, {0, 1}};
            for (auto [pcut, mcut] : prs) {
              if (res.pc < pcut || res.mc < mcut) continue;

              int64_t ps1 = res.ps1, ps2 = res.ps2;
              int64_t ms1 = res.ms1, ms2 = res.ms2;
              for (int i = 0; i < pcut; i++) {
                ps1 -= res.pv[i];
                ps2 -= res.pv[i] * res.pv[i];
              }
              for (int i = 0; i < mcut; i++) {
                ms1 -= res.mv[i];
                ms2 -= res.mv[i] * res.mv[i];
              }

              int64_t cur = (ps1 * ps1 - ps2) / 2 +
                            (ms1 * ms1 - ms2) / 2;
              ans = max<int64_t>(ans, cur);
            }
          } else if (res.pc > 0) {
            int64_t s1 = res.ps1 - res.pv[0] - res.pv[1];
            int64_t s2 = res.ps2 - res.pv[0] * res.pv[0] - res.pv[1] * res.pv[1];
            ans = (s1 * s1 - s2) / 2;
          } else if (res.mc > 0) {
            int64_t s1 = res.ms1 - res.mv[0] - res.mv[1];
            int64_t s2 = res.ms2 - res.mv[0] * res.mv[0] - res.mv[1] * res.mv[1];
            ans = (s1 * s1 - s2) / 2;
          } else {
            ans = 0;
          }
        }
      }

      cout << ans << "\n";
    }
  }

  return 0;
}
