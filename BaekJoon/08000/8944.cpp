// Title : 이진 검색 트리 2
// Link  : https://www.acmicpc.net/problem/8944 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

template <int MAXN, int64_t MOD>
  requires(MAXN >= 0, MOD >= 3)
struct Combination {
  constexpr Combination() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;
    inv[MAXN] = Power(fact[MAXN], MOD - 2);
    for (int i = MAXN; i > 0; i--) inv[i - 1] = (inv[i] * i) % MOD;
  }

  int64_t operator()(int n, int r) const {
    return (((fact[n] * inv[r]) % MOD) * inv[n - r]) % MOD;
  }

  static constexpr int64_t Power(int64_t n, int exp) {
    int64_t res = 1;
    while (exp) {
      if (exp & 1) res = (res * n) % MOD;
      n = (n * n) % MOD;
      exp >>= 1;
    }
    return res;
  }

  int64_t fact[MAXN + 1], inv[MAXN + 1];
};

constexpr int kMax = 20;
constexpr int kMod = 9999991;

constexpr Combination<kMax, kMod> kComb;

struct Node {
  Node() : val(0), child{-1, -1} {}
  Node(int x) : val(x), child{-1, -1} {}

  int val;
  int child[2];
};

vector<Node> nodes;

int64_t Calc(int p, int l, int r) {
  if (p == -1) return 1;

  auto& node = nodes[p];
  int v = node.val;
  int lsz = v - l;
  int rsz = r - v;
  return kComb(lsz + rsz, lsz) * Calc(node.child[0], l, v - 1) * Calc(node.child[1], v + 1, r) % kMod;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto Insert = [&](int x) {
    if (nodes.empty()) {
      nodes.push_back(x);
      return;
    }

    auto node = nodes.data();
    for (;;) {
      int c = node->val < x;
      if (node->child[c] == -1) {
        node->child[c] = nodes.size();
        nodes.push_back(x);
        break;
      }
      node = nodes.data() + node->child[c];
    }
  };

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    nodes.clear();
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      Insert(x);
    }
    cout << Calc(0, 1, n) << "\n";
  }

  return 0;
}