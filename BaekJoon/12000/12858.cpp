// Title : Range GCD
// Link  : https://www.acmicpc.net/problem/12858 
// Time  : 88 ms
// Memory: 6116 KB

#include <bits/stdc++.h>

using namespace std;

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

struct Node {
  Node() : v(0), g(0) {}

  void Add(int64_t x) {
    v += x;
    g = abs(v);
  }

  friend Node operator+(const Node& lhs, const Node& rhs) {
    Node res;
    res.v = lhs.v + rhs.v;
    res.g = GCD(lhs.g, rhs.g);
    return res;
  }

  int64_t v, g;
};

constexpr int kMax = 1 << 17;
Node tree[kMax << 1];

void Update(int idx, int delta) {
  int node = idx + kMax;
  tree[node].Add(delta);
  while (node >>= 1) tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

int64_t QuerySum(int l, int r) {
  int64_t res = 0;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += tree[l++].v;
    if (r & 1) res += tree[--r].v;
  }
  return res;
}

int64_t QueryGCD(int l, int r) {
  int64_t res = 0;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = GCD(res, tree[l++].g);
    if (r & 1) res = GCD(res, tree[--r].g);
  }
  return res;
}

int64_t Query(int l, int r) {
  int64_t s = QuerySum(0, l);
  int64_t g = QueryGCD(l + 1, r);
  return GCD(s, g);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1, prv = 0; i <= n; i++) {
    int cur;
    cin >> cur;
    tree[i + kMax].Add(cur - prv);
    prv = cur;
  }
  for (int i = kMax - 1; i > 0; i--) {
    tree[i] = tree[i << 1] + tree[(i << 1) + 1];
  }

  int m;
  cin >> m;
  while (m--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 0) {
      cout << Query(a, b) << "\n";
    } else {
      Update(a, t);
      Update(b + 1, -t);
    }
  }

  return 0;
}
