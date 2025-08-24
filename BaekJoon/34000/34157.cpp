// Title : Split the SSHS 5
// Link  : https://www.acmicpc.net/problem/34157 
// Time  : 120 ms
// Memory: 17440 KB

#include <bits/stdc++.h>

using namespace std;

template <int32_t MOD>
struct ModInt32 {
  using CT = typename std::conditional<
      (MOD <= std::numeric_limits<int32_t>::max() / 2),
      int32_t,
      int64_t>::type;

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

template <typename V, typename L, typename OP, typename APPLY, typename COMPO>
  requires requires(V va, V vb, L la, L lb, int sz) {
    { OP{}(va, vb) } -> convertible_to<V>;
    { APPLY{}(va, la, sz) } -> convertible_to<V>;
    { COMPO{}(la, lb) } -> convertible_to<L>;
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

  void PushAll() {
    for (int i = 1; i < nmax; i++) {
      Push(i);
    }
  }

  //  private:
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
    Apply(node << 1, lazy[node]);
    Apply(node << 1 | 1, lazy[node]);
    lazy[node] = il;
  }

  void Pull(int node) {
    tree[node] = OP{}(tree[node << 1], tree[node << 1 | 1]);
  }
};

constexpr int kMax = 1e5;

constexpr int kMod = 998244353;
using ModInt = ModInt32<kMod>;

using Node = ModInt;
using Lazy = ModInt;

struct FOp {
  Node operator()(const Node& a, const Node& b) const {
    return a + b;
  }
};

struct FApply {
  Node operator()(const Node& a, const Lazy& b, int sz) const {
    return a * b;
  }
};

struct FCompo {
  Lazy operator()(const Lazy& a, const Lazy& b) const {
    return a * b;
  }
};

LazySegTree<Node, Lazy, FOp, FApply, FCompo> seg;
vector<int> edges[kMax + 1];
vector<int> bombs[kMax + 1];
int in[kMax + 1], out[kMax + 1], nidx;
ModInt inv[kMax + 1];
vector<int> stk;

void Build(int cur, int par) {
  in[cur] = ++nidx;
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    Build(nxt, cur);
  }
  out[cur] = nidx;
}

void Traverse(int cur, int par) {
  stk.clear();
  int bsz = bombs[cur].size();
  for (auto u : bombs[cur]) {
    if (!(in[cur] < in[u] && in[u] <= out[cur])) continue;
    while (!stk.empty() && out[stk.back()] < in[u]) stk.pop_back();
    stk.push_back(u);

    int sz = stk.size();
    int x = bsz - sz;
    seg.Update(in[u], out[u], ModInt(x) * inv[x + 1]);
  }

  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    Traverse(nxt, cur);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  seg.Init(n + 1, 1, 1);

  for (int i = 1; i <= n; i++) {
    int sz;
    cin >> sz;

    auto& vec = bombs[i];
    vec.resize(sz);
    for (auto& e : vec) cin >> e;
  }

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  Build(1, 0);
  for (int i = 1; i <= n; i++) {
    auto& vec = bombs[i];
    sort(vec.begin(), vec.end(), [&](int lhs, int rhs) {
      return in[lhs] < in[rhs];
    });
  }

  inv[0] = 1;
  for (int i = 1; i <= n; i++) {
    inv[i] = ModInt(i).Inv();
  }
  Traverse(1, 0);

  seg.PushAll();
  for (int i = 2; i <= n; i++) {
    cout << seg.tree[in[i] + seg.nmax] << "\n";
  }

  return 0;
}
