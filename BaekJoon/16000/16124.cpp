// Title : 나는 행복합니다
// Link  : https://www.acmicpc.net/problem/16124 
// Time  : 680 ms
// Memory: 187320 KB

#include <bits/stdc++.h>

using namespace std;

// https://github.com/Akrobatik/ps/blob/main/template/modint.cpp
template <int32_t MOD>
struct ModInt32 {
  using CT = conditional_t<MOD <= numeric_limits<int32_t>::max() / 2, int32_t, int64_t>;

  constexpr ModInt32() : val(0) {}
  constexpr ModInt32(int32_t x) : val((x %= MOD) < 0 ? x + MOD : x) {}
  constexpr ModInt32(int64_t x) : val((x %= MOD) < 0 ? x + MOD : x) {}
  constexpr ModInt32(__int128_t x) : val((x %= MOD) < 0 ? x + MOD : x) {}

  constexpr ModInt32 Pow(int64_t exp) const {
    int64_t n = val, x = 1;
    while (exp) {
      if (exp & 1) x = x * n % MOD;
      n = n * n % MOD;
      exp >>= 1;
    }

    ModInt32 res;
    res.val = x;
    return res;
  }

  constexpr ModInt32 Inv() const {
    return Pow(MOD - 2);
  }

  constexpr ModInt32& operator++() {
    if (++val == MOD) val = 0;
    return *this;
  }

  constexpr ModInt32 operator++(int) {
    ModInt32 tmp(*this);
    operator++();
    return tmp;
  }

  constexpr ModInt32& operator+=(const ModInt32& other) {
    CT x = (CT)val + other.val;
    if (x >= MOD) x -= MOD;
    val = x;
    return *this;
  }

  constexpr ModInt32& operator-=(const ModInt32& other) {
    CT x = (CT)val + (MOD - other.val);
    if (x >= MOD) x -= MOD;
    val = x;
    return *this;
  }

  constexpr ModInt32& operator*=(const ModInt32& other) {
    val = (int64_t)val * other.val % MOD;
    return *this;
  }

  constexpr ModInt32& operator/=(const ModInt32& other) {
    *this *= other.Inv();
    return *this;
  }

  constexpr ModInt32 operator-() const {
    ModInt32 res;
    if (val) res.val = MOD - val;
    return res;
  }

  constexpr ModInt32 operator+(const ModInt32& rhs) const {
    return ModInt32(*this) += rhs;
  }

  constexpr ModInt32 operator-(const ModInt32& rhs) const {
    return ModInt32(*this) -= rhs;
  }

  constexpr ModInt32 operator*(const ModInt32& rhs) const {
    return ModInt32(*this) *= rhs;
  }

  constexpr ModInt32 operator/(const ModInt32& rhs) const {
    return ModInt32(*this) /= rhs;
  }

  constexpr bool operator!() const {
    return val == 0;
  }

  friend istream& operator>>(istream& is, ModInt32& num) {
    is >> num.val;
    if ((num.val %= MOD) < 0) num.val += MOD;
    return is;
  }

  friend ostream& operator<<(ostream& os, const ModInt32& num) {
    os << num.val;
    return os;
  }

  int32_t val;
};

constexpr int kMod = 998244353;
using ModInt = ModInt32<kMod>;

// https://github.com/Akrobatik/ps/blob/main/template/lazy_segment_tree.cpp
template <typename V, typename L, typename OP, typename APPLY, typename COMPO>
  requires requires(V va, V vb, L la, L lb, int sz) {
    { OP{}(va, vb) } -> convertible_to<V>;
    { APPLY{}(va, la, sz) } -> convertible_to<V>;
    { COMPO{}(la, lb) } -> convertible_to<L>;
    { la == lb } -> convertible_to<bool>;
  }
struct LazySegTree {
  void Init(int n, const V& ival, const L& ilzy) {
    nmax = bit_ceil((uint32_t)n);
    nlog = countr_zero((uint32_t)nmax);
    iv = ival, il = ilzy;
    tree.assign(nmax << 1, iv);
    lazy.assign(nmax << 1, il);
    sz.resize(nmax << 1);
    sz[1] = nmax;
    for (int i = 1; i < nmax; i++) {
      sz[i << 1] = sz[i << 1 | 1] = sz[i] >> 1;
    }
  }

  void Set(int idx, const V& val) {
    tree[idx + nmax] = val;
  }

  void Build() {
    for (int i = nmax - 1; i > 0; i--) {
      tree[i] = OP{}(tree[i << 1], tree[i << 1 | 1]);
    }
  }

  void Update(int l, int r, const L& lzy) {
    l += nmax, r += nmax + 1;
    for (int i = nlog; i > 0; i--) {
      if (Check(l, i)) Push(l >> i);
      if (Check(r, i)) Push((r - 1) >> i);
    }

    for (int ll = l, rr = r; ll < rr; ll >>= 1, rr >>= 1) {
      if (ll & 1) Apply(ll++, lzy);
      if (rr & 1) Apply(--rr, lzy);
    }

    for (int i = 1; i <= nlog; i++) {
      if (Check(l, i)) Pull(l >> i);
      if (Check(r, i)) Pull((r - 1) >> i);
    }
  }

  V Query(int idx) {
    int node = idx + nmax;
    for (int i = nlog; i > 0; i--) Push(node >> i);
    return tree[node];
  }

  V Query(int l, int r) {
    V lv = iv, rv = iv;

    l += nmax, r += nmax + 1;
    for (int i = nlog; i > 0; i--) {
      if (Check(l, i)) Push(l >> i);
      if (Check(r, i)) Push((r - 1) >> i);
    }

    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lv = OP{}(lv, tree[l++]);
      if (r & 1) rv = OP{}(tree[--r], rv);
    }
    return OP{}(lv, rv);
  }

 private:
  int nmax, nlog;
  V iv;
  L il;
  vector<V> tree;
  vector<L> lazy;
  vector<int> sz;

  bool Check(int x, int shift) {
    int y = (x >> shift) << shift;
    return x != y;
  }

  void Apply(int node, const L& lzy) {
    tree[node] = APPLY{}(tree[node], lzy, sz[node]);
    if (node < nmax) lazy[node] = COMPO{}(lazy[node], lzy);
  }

  void Push(int node) {
    if (lazy[node] == il) return;
    Apply(node << 1, lazy[node]);
    Apply(node << 1 | 1, lazy[node]);
    lazy[node] = il;
  }

  void Pull(int node) {
    tree[node] = OP{}(tree[node << 1], tree[node << 1 | 1]);
  }
};

constexpr int kMax = 1e6;

ModInt pw[kMax + 1];

struct Node {
  Node() : sz(0), val{} {}
  Node(int x) : sz(1), val{} { val[x] = 1; }

  int sz;
  ModInt val[10];
};

struct Lazy {
  Lazy() : table{} { table.fill(-1); }
  Lazy(int from, int to) : Lazy() { table[from] = to; }

  constexpr bool operator==(const Lazy& other) const {
    for (int i = 0; i < 10; i++) {
      if (table[i] == other.table[i]) continue;
      return false;
    }
    return true;
  }

  array<int, 10> table;
};

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    Node res;
    res.sz = a.sz + b.sz;
    for (int i = 0; i < 10; i++) {
      res.val[i] = a.val[i] * pw[b.sz] + b.val[i];
    }
    return res;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    Node res;
    res.sz = a.sz;
    for (int i = 0; i < 10; i++) {
      int to = (b.table[i] != -1 ? b.table[i] : i);
      res.val[to] += a.val[i];
    }
    return res;
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    Lazy res;
    for (int i = 0; i < 10; i++) {
      if (a.table[i] != -1) {
        int x = a.table[i];
        if (b.table[x] != -1) {
          res.table[i] = b.table[x];
        } else {
          res.table[i] = x;
        }
      } else {
        res.table[i] = b.table[i];
      }
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  pw[0] = 1;
  for (int i = 1; i <= kMax; i++) pw[i] = pw[i - 1] * 10;

  string s;
  int q;
  cin >> s >> q;
  int n = s.size();

  LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
  seg.Init(n + 1, Node(), Lazy());
  for (int i = 0; i < n; i++) {
    seg.Set(i + 1, s[i] - '0');
  }
  seg.Build();

  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int l, r, from, to;
      cin >> l >> r >> from >> to;
      seg.Update(l, r, Lazy(from, to));
    } else {
      int l, r;
      cin >> l >> r;
      auto res = seg.Query(l, r);
      ModInt ans = 0;
      for (int i = 1; i < 10; i++) {
        ans += res.val[i] * i;
      }
      cout << ans << "\n";
    }
  }

  return 0;
}