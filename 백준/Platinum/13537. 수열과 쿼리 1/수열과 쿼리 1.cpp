#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 17;

vector<int> tree[kMax << 1];
int caps[kMax << 1];

int Query(int idx, int k) {
  auto& t = tree[idx];
  return t.end() - upper_bound(t.begin(), t.end(), k);
}

int Query(int l, int r, int k) {
  int res = 0;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += Query(l++, k);
    if (r & 1) res += Query(--r, k);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  caps[1] = kMax;
  tree[1].reserve(kMax);
  for (int i = 2; i < (kMax << 1); i++) {
    caps[i] = caps[i >> 1] >> 1;
    tree[i].reserve(caps[i]);
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int idx = kMax + i;
    while (idx) tree[idx].push_back(x), idx >>= 1;
  }

  for (int i = 1; i < kMax; i++) {
    sort(tree[i].begin(), tree[i].end());
  }

  int m;
  cin >> m;
  while (m--) {
    int i, j, k;
    cin >> i >> j >> k;
    cout << Query(i - 1, j - 1, k) << "\n";
  }

  return 0;
}
