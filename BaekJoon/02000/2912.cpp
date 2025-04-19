// Title : 백설공주와 난쟁이
// Link  : https://www.acmicpc.net/problem/2912 
// Time  : 40 ms
// Memory: 12784 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 19;

pair<int, int> tree[kMax << 1];

pair<int, int> Merge(const pair<int, int>& lhs, const pair<int, int>& rhs) {
  int mx, mc;
  auto [lx, lc] = lhs;
  auto [rx, rc] = rhs;
  if (lx == rx) {
    mx = lx, mc = lc + rc;
  } else if (lc > rc) {
    mx = lx, mc = lc - rc;
  } else if (lc < rc) {
    mx = rx, mc = rc - lc;
  } else {
    mx = mc = 0;
  }
  return {mx, mc};
}

pair<int, int> Query(int l, int r) {
  pair<int, int> res{};
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = Merge(res, tree[l++]);
    if (r & 1) res = Merge(res, tree[--r]);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, c;
  cin >> n >> c;
  vector<vector<int>> memo(c + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    tree[i + kMax] = {x, 1};
    memo[x].push_back(i);
  }

  auto Count = [&](int l, int r, int x) {
    return upper_bound(memo[x].begin(), memo[x].end(), r) - lower_bound(memo[x].begin(), memo[x].end(), l);
  };

  int idx = kMax;
  while (--idx) tree[idx] = Merge(tree[idx << 1], tree[(idx << 1) + 1]);

  int m;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    auto [x, _] = Query(l - 1, r - 1);
    if (x && ((r - l + 1) >> 1) < Count(l - 1, r - 1, x)) {
      cout << "yes " << x << "\n";
    } else {
      cout << "no\n";
    }
  }

  return 0;
}
