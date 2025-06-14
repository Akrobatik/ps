// Title : 수열과 쿼리 26
// Link  : https://www.acmicpc.net/problem/17474 
// Time  : 1572 ms
// Memory: 51172 KB

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : sum(0), max1(-1), max2(-1), maxc(0) {}
  Node(int v) : sum(v), max1(v), max2(-1), maxc(1) {}

  friend Node operator+(const Node& lhs, const Node& rhs) {
    Node res;
    res.sum = lhs.sum + rhs.sum;
    if (lhs.max1 > rhs.max1) {
      res.max1 = lhs.max1;
      res.max2 = max<int>(lhs.max2, rhs.max1);
      res.maxc = lhs.maxc;
    } else if (lhs.max1 < rhs.max1) {
      res.max1 = rhs.max1;
      res.max2 = max<int>(rhs.max2, lhs.max1);
      res.maxc = rhs.maxc;
    } else {
      res.max1 = lhs.max1;
      res.max2 = max<int>(lhs.max2, rhs.max2);
      res.maxc = lhs.maxc + rhs.maxc;
    }
    return res;
  }

  int64_t sum;
  int max1, max2, maxc;
};

constexpr int kMax = 1 << 20;

Node tree[kMax << 1];

void Apply(int v, int node) {
  if (tree[node].max1 <= v) return;
  tree[node].sum -= (int64_t)(tree[node].max1 - v) * tree[node].maxc;
  tree[node].max1 = v;
}

void Push(int node, int b, int e) {
  if (b == e) return;
  Apply(tree[node].max1, node << 1);
  Apply(tree[node].max1, (node << 1) + 1);
}

void Update(int l, int r, int v, int node, int b, int e) {
  if (l > e || b > r || tree[node].max1 <= v) return;
  if (l <= b && e <= r && tree[node].max2 < v) {
    Apply(v, node);
    return;
  }
  if (b == e) return;
  int mid = (b + e) >> 1;
  Push(node, b, e);
  Update(l, r, v, node << 1, b, mid);
  Update(l, r, v, (node << 1) + 1, mid + 1, e);
  tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

Node Query(int l, int r, int node, int b, int e) {
  if (l > e || b > r) return Node();
  if (l <= b && e <= r) return tree[node];
  int mid = (b + e) >> 1;
  Push(node, b, e);
  return Query(l, r, node << 1, b, mid) + Query(l, r, (node << 1) + 1, mid + 1, e);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    tree[i + kMax] = Node(x);
  }
  for (int i = kMax - 1; i; i--) {
    tree[i] = tree[i << 1] + tree[(i << 1) + 1];
  }

  int m;
  cin >> m;
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      Update(l, r, v, 1, 0, kMax - 1);
    } else if (cmd == 2) {
      int l, r;
      cin >> l >> r;
      cout << Query(l, r, 1, 0, kMax - 1).max1 << "\n";
    } else {
      int l, r;
      cin >> l >> r;
      cout << Query(l, r, 1, 0, kMax - 1).sum << "\n";
    }
  }

  return 0;
}