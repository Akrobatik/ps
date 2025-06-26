// Title : 마이마이 순회 돌기
// Link  : https://www.acmicpc.net/problem/34039 
// Time  : 196 ms
// Memory: 7680 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : cnt(0), sum(0) {}

  void Add(int dc, int ds) {
    cnt += dc;
    sum += ds;
  }

  Node& operator+=(const Node& other) {
    cnt += other.cnt;
    sum += other.sum;
    return *this;
  }

  friend Node operator+(const Node& lhs, const Node& rhs) {
    Node res;
    res.cnt = lhs.cnt + rhs.cnt;
    res.sum = lhs.sum + rhs.sum;
    return res;
  }

  int cnt;
  int64_t sum;
};

constexpr int kMax = 1 << 17;
Node tree[kMax << 1];

void Update(int idx, int dc, int ds) {
  int node = idx + kMax;
  while (node) tree[node].Add(dc, ds), node >>= 1;
}

pair<int, int64_t> Query(int l, int r) {
  Node res;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += tree[l++];
    if (r & 1) res += tree[--r];
  }
  return {res.cnt, res.sum};
}

int Count(int maxx, int64_t t) {
  int lo = 0, hi = kMax;
  int mcnt = 0;
  int64_t msum = 0;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    auto [cnt, sum] = Query(0, mid);
    if (sum <= t) {
      lo = mid;
      mcnt = cnt, msum = sum;
    } else {
      hi = mid;
    }
  }

  int rem = maxx - mcnt;
  if (rem) {
    int x = lo + 1;
    int cnt = tree[x + kMax].cnt;
    mcnt += min<int>((t - msum) / x, cnt);
  }
  return mcnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<int> arr(n + q + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    tree[arr[i] + kMax].Add(1, arr[i]);
  }

  for (int i = kMax - 1; i; i--) {
    tree[i] = tree[i << 1] + tree[(i << 1) + 1];
  }

  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int j, v;
      cin >> j >> v;
      Update(arr[j], -1, -arr[j]);
      arr[j] = v;
      Update(arr[j], 1, arr[j]);
    } else if (cmd == 2) {
      int t;
      cin >> t;
      cout << Count(n, t) << "\n";
    } else {
      int v;
      cin >> v;
      arr[++n] = v;
      Update(arr[n], 1, arr[n]);
    }
  }

  return 0;
}
