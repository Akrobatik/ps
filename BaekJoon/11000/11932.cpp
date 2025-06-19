// Title : 트리와 K번째 수
// Link  : https://www.acmicpc.net/problem/11932 
// Time  : 704 ms
// Memory: 36132 KB

#include <bits/stdc++.h>

using namespace std;

struct WaveletTree {
  WaveletTree(vector<int>::iterator b, vector<int>::iterator e, int _lo, int _hi) : lo(_lo), hi(_hi), lnode(nullptr), rnode(nullptr) {
    if (b >= e || lo == hi) return;

    int mid = (lo + hi) >> 1;
    arr.reserve(e - b + 1);
    arr.push_back(0);

    for (auto it = b; it != e; ++it) {
      arr.push_back(arr.back() + (*it <= mid));
    }

    auto pivot = stable_partition(b, e, [&](int x) {
      return x <= mid;
    });

    lnode = new WaveletTree(b, pivot, lo, mid);
    rnode = new WaveletTree(pivot, e, mid + 1, hi);
  }

  int Query(int l, int r, int k) const {
    if (l > r || k < lo) return 0;
    if (hi <= k) return r - l + 1;
    int lb = arr[l - 1], rb = arr[r];
    return lnode->Query(lb + 1, rb, k) + rnode->Query(l - lb, r - rb, k);
  }

  int lo, hi;
  WaveletTree *lnode, *rnode;
  vector<int> arr;
};

vector<int> edges[100001];
int par[100001], depth[100001], heavy[100001], head[100001], order[100001];
int idx;

int Traverse(int cur) {
  int sum = 1, maxx = 0;
  for (auto nxt : edges[cur]) {
    if (nxt == par[cur]) continue;
    par[nxt] = cur, depth[nxt] = depth[cur] + 1;
    int cnt = Traverse(nxt);
    sum += cnt;
    if (maxx < cnt) maxx = cnt, heavy[cur] = nxt;
  }
  return sum;
}

void Decompose(int cur, int h) {
  head[cur] = h, order[cur] = ++idx;
  if (heavy[cur]) Decompose(heavy[cur], h);
  for (auto nxt : edges[cur]) {
    if (nxt == par[cur] || nxt == heavy[cur]) continue;
    Decompose(nxt, nxt);
  }
}

vector<pair<int, int>> GetPath(int u, int v) {
  vector<pair<int, int>> res;
  while (head[u] != head[v]) {
    int hu = head[u], hv = head[v];
    if (depth[hu] > depth[hv]) {
      res.push_back({order[hu], order[u]});
      u = par[head[u]];
    } else {
      res.push_back({order[hv], order[v]});
      v = par[head[v]];
    }
  }
  if (depth[u] > depth[v]) swap(u, v);
  res.push_back({order[u], order[v]});
  return res;
}

int Query(const WaveletTree& tree, int u, int v, int k, int limit) {
  auto path = GetPath(u, v);
  int lo = 0, hi = limit;
  while (lo + 1< hi) {
    int mid = (lo + hi) >> 1;
    int cnt = 0;
    for (auto [l, r] : path) cnt += tree.Query(l, r, mid);
    if (cnt < k) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return hi;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  auto comp = arr;
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());
  for (auto& e : arr) e = (lower_bound(comp.begin(), comp.end(), e) - comp.begin()) + 1;
  int limit = comp.size();

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  Traverse(1);
  Decompose(1, 1);

  vector<int> brr(n);
  for (int i = 0; i < n; i++) {
    brr[order[i + 1] - 1] = arr[i];
  }
  WaveletTree tree(brr.begin(), brr.end(), 1, limit);

  while (m--) {
    int u, v, k;
    cin >> u >> v >> k;
    cout << comp[Query(tree, u, v, k, limit) - 1] << "\n";
  }

  return 0;
}
