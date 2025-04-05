// Title : 수열과 쿼리 1
// Link  : https://www.acmicpc.net/problem/13537
// Time  : 192 ms
// Memory: 20344 KB

#include <bits/stdc++.h>

using namespace std;

struct MergeSortTree {
  void Init(const vector<int>& arr) {
    int n = arr.size();
    nmax = has_single_bit((uint32_t)n) ? n : (1 << (32 - countl_zero((uint32_t)n)));
    tree.clear(), tree.resize(nmax << 1);

    for (int i = 0; i < n; i++) {
      tree[i + nmax].push_back(arr[i]);
    }

    int sz = nmax >> 1;
    while (sz) {
      for (int i = 0; i < sz; i++) {
        int idx = sz + i;
        auto& l = tree[idx << 1];
        auto& r = tree[(idx << 1) + 1];
        tree[idx].resize(l.size() + r.size());
        merge(l.begin(), l.end(), r.begin(), r.end(), tree[idx].begin());
      }
      sz >>= 1;
    }
  }

  int Query(int l, int r, int k) {
    int res = 0;
    for (l += nmax, r += nmax + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res += Query(l++, k);
      if (r & 1) res += Query(--r, k);
    }
    return res;
  }

  int Query(int idx, int k) {
    auto& t = tree[idx];
    return t.end() - upper_bound(t.begin(), t.end(), k);
  }

  int nmax;
  vector<vector<int>> tree;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  MergeSortTree mst;
  mst.Init(arr);

  int m;
  cin >> m;
  while (m--) {
    int i, j, k;
    cin >> i >> j >> k;
    cout << mst.Query(i - 1, j - 1, k) << "\n";
  }

  return 0;
}
