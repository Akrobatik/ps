// Title : MMSQ
// Link  : https://www.acmicpc.net/problem/33956 
// Time  : 192 ms
// Memory: 28644 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = INT64_MAX >> 2;

struct Node {
  Node() : sum(0), minn(0), maxx(0), val(0), fwd{}, bwd{}, valid(false) {}

  Node(int64_t v) : sum(v), minn(v), maxx(v), val(v),  //
                    fwd{v, 0, v + v, v},
                    bwd{v, v + v, 0, v},
                    valid(true) {}

  friend Node operator+(const Node& lhs, const Node& rhs) {
    if (!lhs.valid) return rhs;
    if (!rhs.valid) return lhs;

    Node res(0);
    res.sum = lhs.sum + rhs.sum;
    res.minn = min<int64_t>(lhs.minn, rhs.minn);
    res.maxx = max<int64_t>(lhs.maxx, rhs.maxx);

    for (int i = 0; i < 4; i++) {
      res.fwd[i] = max<int64_t>(lhs.fwd[i], lhs.sum + rhs.fwd[i]);
      res.bwd[i] = max<int64_t>(rhs.bwd[i], rhs.sum + lhs.bwd[i]);
    }

    res.fwd[1] = max<int64_t>(res.fwd[1], lhs.sum - lhs.minn + rhs.fwd[0]);
    res.fwd[2] = max<int64_t>(res.fwd[2], lhs.sum + lhs.maxx + rhs.fwd[0]);
    res.fwd[3] = max<int64_t>({res.fwd[3],
                               lhs.sum + lhs.maxx - lhs.minn + rhs.fwd[0],
                               lhs.sum + lhs.maxx + rhs.fwd[1],
                               lhs.sum - lhs.minn + rhs.fwd[2]});

    res.bwd[0] = max<int64_t>({res.bwd[0],
                               rhs.sum + rhs.maxx - rhs.minn + lhs.bwd[3],
                               rhs.sum + rhs.maxx + lhs.bwd[2],
                               rhs.sum - rhs.minn + lhs.bwd[1]});
    res.bwd[1] = max<int64_t>(res.bwd[1], rhs.sum + rhs.maxx + lhs.bwd[3]);
    res.bwd[2] = max<int64_t>(res.bwd[2], rhs.sum - rhs.minn + lhs.bwd[3]);

    res.val = max<int64_t>(lhs.val, rhs.val);
    for (int i = 0; i < 4; i++) {
      res.val = max<int64_t>(res.val, lhs.bwd[i] + rhs.fwd[i]);
    }
    return res;
  }

  int64_t sum, minn, maxx, val;
  int64_t fwd[4], bwd[4];
  bool valid;
};

constexpr int kMax = 1 << 17;

Node tree[kMax << 1];

void Update(int idx, int val) {
  int node = idx + kMax;
  tree[node] = Node(val);
  node >>= 1;
  while (node) {
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
    node >>= 1;
  }
}

int64_t Query(int l, int r) {
  Node lnode, rnode;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) lnode = lnode + tree[l++];
    if (r & 1) rnode = tree[--r] + rnode;
  }
  Node res = lnode + rnode;
  return res.val;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    Update(i, x);
  }

  while (q--) {
    int cmd, a, b;
    cin >> cmd >> a >> b;
    if (cmd == 1) {
      Update(a - 1, b);
    } else {
      cout << Query(a - 1, b - 1) << "\n";
    }
  }

  return 0;
}
