// Title : 북서풍
// Link  : https://www.acmicpc.net/problem/5419 
// Time  : 360 ms
// Memory: 4052 KB

#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
  void Init(int n) {
    nmax = has_single_bit((uint32_t)n) ? n : (1 << (32 - countl_zero((uint32_t)n)));
    tree.clear(), tree.resize(nmax << 1);
  }

  void Update(int idx, int delta) {
    int node = idx + nmax;
    while (node) tree[node] += delta, node >>= 1;
  }

  int Query(int l, int r) {
    int res = 0;
    for (l += nmax, r += nmax + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res += tree[l++];
      if (r & 1) res += tree[--r];
    }
    return res;
  }

  int nmax;
  vector<int> tree;
};

void Compress(vector<pair<int, int>>& coords) {
  int n = coords.size();
  vector<int> my(n);
  for (int i = 0; i < n; i++) {
    my[i] = coords[i].first;
  }
  sort(my.begin(), my.end());
  auto ye = unique(my.begin(), my.end());
  for (auto& [y, x] : coords) {
    y = lower_bound(my.begin(), ye, y) - my.begin();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  SegmentTree tree;
  vector<pair<int, int>> coords;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    tree.Init(n);
    coords.resize(n);
    for (auto& [y, x] : coords) cin >> x >> y;
    Compress(coords);

    sort(coords.begin(), coords.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
      auto [ly, lx] = lhs;
      auto [ry, rx] = rhs;
      return lx > rx || (lx == rx && ly < ry);
    });

    int64_t sum = 0;
    for (auto [y, x] : coords) {
      sum += tree.Query(0, y);
      tree.Update(y, 1);
    }
    cout << sum << "\n";
  }

  return 0;
}
