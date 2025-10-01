// Title : Harvest
// Link  : https://www.acmicpc.net/problem/26449 
// Time  : 244 ms
// Memory: 43796 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 19;
vector<int> tree[kMax << 1];

void Update(int l, int r, int x) {
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) tree[l++].push_back(x);
    if (r & 1) tree[--r].push_back(x);
  }
}

vector<int> Query(int idx) {
  vector<int> res;
  int sz = 0;
  for (int i = idx + kMax; i > 0; i >>= 1) {
    sz += tree[i].size();
  }

  res.reserve(sz);
  for (int i = idx + kMax; i > 0; i >>= 1) {
    if (tree[i].empty()) continue;

    int old = res.size();
    res.resize(old + tree[i].size());
    copy(tree[i].begin(), tree[i].end(), res.begin() + old);
    tree[i].clear();
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> memo;
  vector<pair<int, int>> arr(n);
  for (auto& [l, r] : arr) {
    cin >> l >> r;
    memo.push_back(l);
    memo.push_back(r);
  }

  int k;
  cin >> k;
  vector<int> brr(k);
  for (auto& e : brr) {
    cin >> e;
    memo.push_back(e);
  }

  sort(memo.begin(), memo.end());
  memo.erase(unique(memo.begin(), memo.end()), memo.end());

  for (auto& [l, r] : arr) {
    l = lower_bound(memo.begin(), memo.end(), l) - memo.begin();
    r = lower_bound(memo.begin(), memo.end(), r) - memo.begin();
  }

  for (auto& e : brr) {
    e = lower_bound(memo.begin(), memo.end(), e) - memo.begin();
  }

  for (int i = 0; i < n; i++) {
    auto [l, r] = arr[i];
    Update(l, r, i);
  }

  int cnt = 0;
  vector<bool> vis(n);
  for (auto e : brr) {
    auto res = Query(e);
    for (auto e : res) {
      if (vis[e]) continue;
      vis[e] = true;
      ++cnt;
    }
  }
  cout << cnt;

  return 0;
}