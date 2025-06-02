// Title : 금광
// Link  : https://www.acmicpc.net/problem/10167 
// Time  : 792 ms
// Memory: 2644 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

constexpr int kMax = 1 << 12;
constexpr int64_t kInf = INT64_MAX >> 2;

struct Node {
  Node() : val(0), sum(0), fwd(0), bwd(0) {}
  Node(int64_t v) : val(v), sum(v), fwd(v), bwd(v) {}

  friend Node operator+(const Node& lhs, const Node& rhs) {
    Node res;
    res.val = max<int64_t>({lhs.val, rhs.val, lhs.bwd + rhs.fwd});
    res.sum = lhs.sum + rhs.sum;
    res.fwd = max<int64_t>(lhs.fwd, lhs.sum + rhs.fwd);
    res.bwd = max<int64_t>(rhs.bwd, rhs.sum + lhs.bwd);
    return res;
  }

  int64_t val, sum, fwd, bwd;
};

Node tree[kMax << 1];

void Update(int idx, int64_t delta) {
  int node = idx + kMax;
  tree[node] = Node(tree[node].val + delta);
  node >>= 1;
  while (node) {
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
    node >>= 1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<tup> arr(n);
  int64_t maxx = INT64_MIN;
  for (auto& [x, y, w] : arr) cin >> x >> y >> w, maxx = max<int64_t>(maxx, w);

  sort(arr.begin(), arr.end(), [](const tup& lhs, const tup& rhs) {
    return get<0>(lhs) < get<0>(rhs);
  });

  int last = get<0>(arr[0]), idx = 0;
  for (auto& [x, y, w] : arr) {
    if (last != x) last = x, ++idx;
    x = idx;
  }

  sort(arr.begin(), arr.end(), [](const tup& lhs, const tup& rhs) {
    return get<1>(lhs) < get<1>(rhs);
  });

  vector<vector<pair<int, int>>> brr;
  auto vec = &brr.emplace_back();

  last = get<1>(arr[0]);
  for (auto& [x, y, w] : arr) {
    if (last != y) last = y, vec = &brr.emplace_back();
    vec->push_back({x, w});
  }

  int maxh = brr.size();
  for (int k = 0; k < maxh; k++) {
    for (int i = maxh - 1; i >= k; i--) {
      for (auto [x, w] : brr[i]) Update(x, w);
      maxx = max<int64_t>(maxx, tree[1].val);
    }

    for (int i = maxh - 1; i > k; i--) {
      for (auto [x, w] : brr[i]) Update(x, -w);
      maxx = max<int64_t>(maxx, tree[1].val);
    }
    for (auto [x, w] : brr[k]) Update(x, -w);
  }
  cout << maxx;

  return 0;
}
