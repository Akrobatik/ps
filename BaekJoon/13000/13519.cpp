// Title : 트리와 쿼리 10
// Link  : https://www.acmicpc.net/problem/13519 
// Time  : 408 ms
// Memory: 19804 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : val(0), sum(0), fwd(0), bwd(0), has_lazy(0), lazy(0) {}

  void Set(int v) {
    sum = v;
    val = fwd = bwd = max<int>(v, 0);
  }

  friend Node operator+(const Node& lhs, const Node& rhs) {
    Node res;
    res.val = max<int>({lhs.val, rhs.val, lhs.bwd + rhs.fwd});
    res.sum = lhs.sum + rhs.sum;
    res.fwd = max<int>(lhs.fwd, lhs.sum + rhs.fwd);
    res.bwd = max<int>(rhs.bwd, rhs.sum + lhs.bwd);
    return res;
  }

  int val, sum, fwd, bwd;
  int has_lazy, lazy;
};

constexpr int kMax = 1 << 17;

Node tree[kMax << 1];
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

pair<vector<pair<int, int>>, vector<pair<int, int>>> GetPath(int u, int v) {
  vector<pair<int, int>> lres, rres;
  if (order[u] > order[v]) swap(u, v);
  while (head[u] != head[v]) {
    int hu = head[u], hv = head[v];
    if (depth[hu] > depth[hv]) {
      lres.push_back({order[hu], order[u]});
      u = par[head[u]];
    } else {
      rres.push_back({order[hv], order[v]});
      v = par[head[v]];
    }
  }
  if (depth[u] > depth[v]) {
    lres.push_back({order[v], order[u]});
  } else {
    rres.push_back({order[u], order[v]});
  }
  return {lres, rres};
}

void Push(int node, int b, int e) {
  if (tree[node].has_lazy == 0) return;
  tree[node].Set(tree[node].lazy * (e - b + 1));
  if (b != e) {
    auto& lnode = tree[node << 1];
    auto& rnode = tree[(node << 1) + 1];
    lnode.has_lazy = rnode.has_lazy = 1;
    lnode.lazy = rnode.lazy = tree[node].lazy;
  }
  tree[node].has_lazy = 0;
}

void Update(int node, int b, int e, int l, int r, int v) {
  bool fit = (l <= b && e <= r);
  if (fit) tree[node].has_lazy = 1, tree[node].lazy = v;
  Push(node, b, e);
  if (l > e || b > r || fit) return;
  int mid = (b + e) >> 1;
  Update(node << 1, b, mid, l, r, v);
  Update((node << 1) + 1, mid + 1, e, l, r, v);
  tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

Node Query(int node, int b, int e, int l, int r) {
  Push(node, b, e);
  if (l > e || b > r) return Node();
  if (l <= b && e <= r) return tree[node];
  int mid = (b + e) >> 1;
  return Query(node << 1, b, mid, l, r) + Query((node << 1) + 1, mid + 1, e, l, r);
}

void Update(int u, int v, int w) {
  auto [lpath, rpath] = GetPath(u, v);
  for (auto [l, r] : lpath) {
    Update(1, 0, kMax - 1, l, r, w);
  }
  for (auto [l, r] : rpath) {
    Update(1, 0, kMax - 1, l, r, w);
  }
}

int Query(int u, int v) {
  Node lnode, rnode;
  auto [lpath, rpath] = GetPath(u, v);
  for (auto [l, r] : lpath) {
    lnode = Query(1, 0, kMax - 1, l, r) + lnode;
  }
  for (auto [l, r] : rpath) {
    rnode = Query(1, 0, kMax - 1, l, r) + rnode;
  }
  swap(lnode.fwd, lnode.bwd);
  Node res = lnode + rnode;
  return res.val;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  Traverse(1);
  Decompose(1, 1);

  for (int i = 1; i <= n; i++) Update(1, 0, kMax - 1, order[i], order[i], arr[i - 1]);

  int m;
  cin >> m;
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int u, v;
      cin >> u >> v;
      cout << Query(u, v) << "\n";
    } else {
      int u, v, w;
      cin >> u >> v >> w;
      Update(u, v, w);
    }
  }

  return 0;
}
