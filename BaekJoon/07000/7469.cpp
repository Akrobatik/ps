// Title : K번째 수
// Link  : https://www.acmicpc.net/problem/7469 
// Time  : 120 ms
// Memory: 19952 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 17;

vector<int> tree[kMax << 1];

int Query(int idx, int x) {
  auto& node = tree[idx];
  return upper_bound(node.begin(), node.end(), x) - node.begin();
}

int Query(int l, int r, int x) {
  int res = 0;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += Query(l++, x);
    if (r & 1) res += Query(--r, x);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    auto& node = tree[i + kMax];
    node.resize(1);
    cin >> node[0];
  }

  for (int i = kMax - 1; i; i--) {
    auto& node = tree[i];
    auto& l = tree[i << 1];
    auto& r = tree[(i << 1) + 1];
    node.resize(l.size() + r.size());
    merge(l.begin(), l.end(), r.begin(), r.end(), node.begin());
  }

  while (m--) {
    int l, r, k;
    cin >> l >> r >> k;
    --l, --r;
    int lo = -1e9 - 1, hi = 1e9;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      if (Query(l, r, mid) < k) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    cout << hi << "\n";
  }

  return 0;
}
