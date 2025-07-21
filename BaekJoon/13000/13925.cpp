// Title : 수열과 쿼리 13
// Link  : https://www.acmicpc.net/problem/13925 
// Time  : 176 ms
// Memory: 5092 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 17;
constexpr int kMod = 1e9 + 7;

struct Node {
  Node() : val(0), mul(1), add(0) {}

  bool HasLazy() const {
    return mul != 1 || add != 0;
  }

  void Apply(int sz) {
    val = ((int64_t)val * mul + (int64_t)add * sz) % kMod;
    mul = 1, add = 0;
  }

  void Lazy(int m, int a) {
    mul = (int64_t)mul * m % kMod;
    add = ((int64_t)add * m + a) % kMod;
  }

  void Merge(const Node& lhs, const Node& rhs) {
    val = lhs.val + rhs.val;
    if (val >= kMod) val -= kMod;
  }

  int val, mul, add;
};

Node tree[kMax << 1];

void Push(int node, int b, int e) {
  if (!tree[node].HasLazy()) return;
  int mul = tree[node].mul;
  int add = tree[node].add;
  tree[node].Apply(e - b + 1);
  if (b != e) {
    tree[node << 1].Lazy(mul, add);
    tree[(node << 1) + 1].Lazy(mul, add);
  }
}

void Update(int node, int b, int e, int l, int r, int mul, int add) {
  bool fit = (l <= b && e <= r);
  if (fit) tree[node].Lazy(mul, add);
  Push(node, b, e);
  if (l > e || b > r || fit) return;
  int mid = (b + e) >> 1;
  Update(node << 1, b, mid, l, r, mul, add);
  Update((node << 1) + 1, mid + 1, e, l, r, mul, add);
  tree[node].Merge(tree[node << 1], tree[(node << 1) + 1]);
}

int Query(int node, int b, int e, int l, int r) {
  Push(node, b, e);
  if (l > e || b > r) return 0;
  if (l <= b && e <= r) return tree[node].val;
  int mid = (b + e) >> 1;
  int res = Query(node << 1, b, mid, l, r) + Query((node << 1) + 1, mid + 1, e, l, r);
  return res >= kMod ? res - kMod : res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> tree[i + kMax].val;
  }
  for (int i = kMax - 1; i > 0; i--) {
    tree[i].Merge(tree[i << 1], tree[(i << 1) + 1]);
  }

  int m;
  cin >> m;
  while (m--) {
    int cmd;
    cin >> cmd;
    switch (cmd) {
      case 1: {
        int x, y, v;
        cin >> x >> y >> v;
        Update(1, 0, kMax - 1, x, y, 1, v);
      } break;
      case 2: {
        int x, y, v;
        cin >> x >> y >> v;
        Update(1, 0, kMax - 1, x, y, v, 0);
      } break;
      case 3: {
        int x, y, v;
        cin >> x >> y >> v;
        Update(1, 0, kMax - 1, x, y, 0, v);
      } break;
      case 4: {
        int x, y;
        cin >> x >> y;
        cout << Query(1, 0, kMax - 1, x, y) << "\n";
      } break;
    }
  }

  return 0;
}
