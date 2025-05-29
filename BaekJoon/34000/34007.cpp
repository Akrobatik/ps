// Title : 대충 만들어진 인내의 숲
// Link  : https://www.acmicpc.net/problem/34007 
// Time  : 168 ms
// Memory: 16276 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = 2e9 + 1;

struct SegmentTree {
  void Init(int n) {
    nmax = has_single_bit((uint32_t)n) ? n : (1 << (32 - countl_zero((uint32_t)n)));
    tree.clear(), tree.resize(nmax << 1, {kInf, -1});
  }

  void Update(int idx, const pair<int, int>& value) {
    int node = idx + nmax;
    tree[node] = value;
    while ((node >>= 1)) tree[node] = min<pair<int, int>>(tree[node << 1], tree[(node << 1) + 1]);
  }

  int Query(int l, int r) {
    pair<int, int> res = {kInf, -1};
    for (l += nmax, r += nmax + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = min<pair<int, int>>(tree[l++], res);
      if (r & 1) res = min<pair<int, int>>(tree[--r], res);
    }
    return res.second;
  }

  int nmax;
  vector<pair<int, int>> tree;
};

vector<pair<int, int>> coords;
vector<pair<int, int>> lr;
vector<bool> visited;
SegmentTree tree;

void Solve() {
  int n, a, b;
  cin >> n >> a >> b;

  coords.resize(n);
  for (auto& [x, y] : coords) cin >> x >> y;
  auto [dx, dy] = coords.back();
  sort(coords.begin(), coords.end());

  tree.Init(n);
  lr.resize(n);
  int l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    while (coords[i].first - coords[l].first > a) ++l;
    while (r + 1 != n && coords[r + 1].first - coords[i].first <= a) ++r; 
    lr[i] = {l, r};
    tree.Update(i, {coords[i].second, i});
  }

  queue<int> q;
  visited.assign(n, false);

  auto Push = [&](int x) {
    if (visited[x]) return;
    visited[x] = true;
    q.push(x);
  };

  for (int i = 0; i < n; i++) {
    if (coords[i].second > b) continue;
    Push(i);
    tree.Update(i, {kInf, -1});
  }

  bool ok = false;
  while (!q.empty()) {
    int x = q.front();
    q.pop();

    ok = (dx == coords[x].first && dy == coords[x].second);
    if (ok) break;

    int limit = coords[x].second + b;
    auto [l, r] = lr[x];
    for (;;) {
      auto nxt = tree.Query(l, r);
      if (nxt == -1 || coords[nxt].second > limit) break;
      Push(nxt);
      tree.Update(nxt, {kInf, -1});
    }
  }

  cout << (ok ? "YES\n" : "NO\n");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) Solve();

  return 0;
}
