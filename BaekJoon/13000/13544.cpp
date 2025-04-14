// Title : 수열과 쿼리 3
// Link  : https://www.acmicpc.net/problem/13544 
// Time  : 188 ms
// Memory: 19952 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 17;

vector<int> tree[kMax << 1];

int Count(const vector<int>& arr, int x) {
  return arr.end() - upper_bound(arr.begin(), arr.end(), x);
}

int Query(int l, int r, int x) {
  int res = 0;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += Count(tree[l++], x);
    if (r & 1) res += Count(tree[--r], x);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    tree[i + kMax].resize(1);
    cin >> tree[i + kMax][0];
  }

  int node = kMax;
  while (--node) {
    auto& m = tree[node];
    auto& l = tree[node << 1];
    auto& r = tree[(node << 1) + 1];
    m.resize(l.size() + r.size());
    merge(l.begin(), l.end(), r.begin(), r.end(), m.begin());
  }

  int m, ans = 0;
  cin >> m;
  while (m--) {
    int l, r, x;
    cin >> l >> r >> x;
    ans = Query((l ^ ans) - 1, (r ^ ans) - 1, x ^ ans);
    cout << ans << "\n";
  }

  return 0;
}
