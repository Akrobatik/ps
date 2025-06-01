// Title : 광부 호석
// Link  : https://www.acmicpc.net/problem/21279 
// Time  : 84 ms
// Memory: 8464 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

struct Node {
  Node() : cnt(0), val(0) {}

  friend Node operator+(const Node& lhs, const Node& rhs) {
    Node res;
    res.cnt = lhs.cnt + rhs.cnt;
    res.val = lhs.val + rhs.val;
    return res;
  }

  void Add(int64_t delta) {
    ++cnt;
    val += delta;
  }

  int64_t cnt, val;
};

constexpr int kMax = 1 << 17;

Node tree[kMax << 1];

void Update(int idx, int64_t delta) {
  int node = idx + kMax;
  while (node) tree[node].Add(delta), node >>= 1;
}

pair<int64_t, int64_t> Query(int l, int r) {
  Node lnode, rnode;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) lnode = lnode + tree[l++];
    if (r & 1) rnode = tree[--r] + rnode;
  }
  Node res = lnode + rnode;
  return {res.cnt, res.val};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, c;
  cin >> n >> c;
  vector<tup> arr(n);
  for (auto& [y, x, v] : arr) cin >> x >> y >> v;
  sort(arr.begin(), arr.end());

  int64_t maxx = 0;

  int idx = 0, r = 1e5;
  while (idx < n) {
    int y = get<0>(arr[idx]);
    while (idx < n && y == get<0>(arr[idx])) {
      auto [yy, xx, vv] = arr[idx++];
      Update(xx, vv);
    }

    int lo = -1, hi = r + 1;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      auto [cnt, val] = Query(0, mid);
      if (cnt <= c) {
        lo = mid;
        maxx = max<int64_t>(maxx, val);
      } else {
        hi = mid;
      }
    }

    if (lo < 0) break;
    r = lo;
  }
  cout << maxx;

  return 0;
}
