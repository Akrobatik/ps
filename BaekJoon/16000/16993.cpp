// Title : 연속합과 쿼리
// Link  : https://www.acmicpc.net/problem/16993 
// Time  : 56 ms
// Memory: 6116 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : val(INT_MIN), sum(0), fwd(0), bwd(0) {}
  Node(int x) : val(x), sum(x), fwd(x), bwd(x) {}

  friend Node operator+(const Node& lhs, const Node& rhs) {
    Node res;
    res.val = max<int>({lhs.val, rhs.val, lhs.bwd + rhs.fwd});
    res.sum = lhs.sum + rhs.sum;
    res.fwd = max<int>(lhs.fwd, lhs.sum + rhs.fwd);
    res.bwd = max<int>(rhs.bwd, rhs.sum + lhs.bwd);
    return res;
  }

  int val, sum, fwd, bwd;
};

constexpr int kMax = 1 << 17;
Node tree[kMax << 1];

int Query(int l, int r) {
  Node lnode, rnode;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) lnode = lnode + tree[l++];
    if (r & 1) rnode = tree[--r] + rnode;
  }
  return (lnode + rnode).val;
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
  for (int i = kMax - 1; i > 0; i--) {
    tree[i] = tree[i << 1] + tree[(i << 1) + 1];
  }

  int m;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << Query(l, r) << "\n";
  }

  return 0;
}
