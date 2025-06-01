// Title : 🍕😋🤮
// Link  : https://www.acmicpc.net/problem/33949 
// Time  : 216 ms
// Memory: 30692 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 18;
constexpr int64_t kInf = INT64_MAX >> 2;

struct Node {
  Node() : val(0), minn{kInf, kInf, kInf}, maxx{-kInf, -kInf, -kInf} {}
  Node(int64_t v) : val(v), minn{v, v, v}, maxx{v, v, v} {}

  friend Node operator+(const Node& lhs, const Node& rhs) {
    Node res;
    res.val = lhs.val + rhs.val;
    res.minn[0] = min<int64_t>(lhs.minn[0], lhs.val + rhs.minn[0]);
    res.minn[1] = min<int64_t>(rhs.minn[1], rhs.val + lhs.minn[1]);
    res.minn[2] = min<int64_t>({lhs.minn[2], rhs.minn[2], lhs.minn[1] + rhs.minn[0]});
    res.maxx[0] = max<int64_t>(lhs.maxx[0], lhs.val + rhs.maxx[0]);
    res.maxx[1] = max<int64_t>(rhs.maxx[1], rhs.val + lhs.maxx[1]);
    res.maxx[2] = max<int64_t>({lhs.maxx[2], rhs.maxx[2], lhs.maxx[1] + rhs.maxx[0]});
    return res;
  }

  int64_t val, minn[3], maxx[3];
};

Node tree[kMax << 1];

void Update(int idx, int64_t delta) {
  int node = idx + kMax;
  tree[node] = Node(tree[node].val + delta);
  while ((node >>= 1)) tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; i++) {
    tree[i + kMax] = Node(0);
  }

  for (int i = kMax - 1; i; i--) {
    tree[i] = tree[i << 1] + tree[(i << 1) + 1];
  }

  auto& root = tree[1];

  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int a, b;
      cin >> a >> b;
      Update(a - 1, b);
    } else {
      if (root.val == root.minn[2]) {
        cout << root.maxx[2] << "\n";
      } else {
        cout << max<int64_t>(root.maxx[2], root.val - root.minn[2]) << "\n";
      }
    }
  }

  return 0;
}
