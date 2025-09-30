// Title : Designing a Tree
// Link  : https://www.acmicpc.net/problem/34532 
// Time  : 1080 ms
// Memory: 107332 KB

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
  for (int i = 1; i < n; i++) {
    int l, r;
    cin >> l >> r;
    Update(l, r, i);
  }

  vector<int> ans(n + 1), stk{n};
  vector<bool> vis(n + 1);

  int rem = n - 1;
  while (!stk.empty()) {
    int cur = stk.back();
    stk.pop_back();

    auto nxt = Query(cur);
    for (auto e : nxt) {
      if (vis[e]) continue;
      --rem;
      vis[e] = true;
      ans[e] = cur;
      stk.push_back(e);
    }
  }

  if (rem != 0) {
    cout << "NO";
    return 0;
  }

  cout << "YES\n";
  for (int i = 1; i < n; i++) cout << ans[i] << " ";

  return 0;
}