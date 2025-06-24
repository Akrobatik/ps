// Title : 국제 메시 기구
// Link  : https://www.acmicpc.net/problem/17429 
// Time  : 1328 ms
// Memory: 92396 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : val(0), mul(1), add(0) {}

  bool HasLazy() const {
    return mul != 1 || add != 0;
  }

  void Apply(uint32_t sz) {
    val = val * mul + add * sz;
    mul = 1, add = 0;
  }

  void Lazy(uint32_t m, uint32_t a) {
    mul = mul * m;
    add = add * m + a;
  }

  void Merge(const Node& lhs, const Node& rhs) {
    assert(!(HasLazy() || lhs.HasLazy() || rhs.HasLazy()));
    val = lhs.val + rhs.val;
  }

  uint32_t val, mul, add;
};

constexpr int kMax = 1 << 19;

Node tree[kMax << 1];

void Push(int node, int b, int e) {
  if (!tree[node].HasLazy()) return;
  uint32_t mul = tree[node].mul;
  uint32_t add = tree[node].add;
  tree[node].Apply(e - b + 1);
  if (b != e) {
    tree[node << 1].Lazy(mul, add);
    tree[(node << 1) + 1].Lazy(mul, add);
  }
}

void Update(int node, int b, int e, int l, int r, uint32_t mul, uint32_t add) {
  bool fit = (l <= b && e <= r);
  if (fit) tree[node].Lazy(mul, add);
  Push(node, b, e);
  if (l > e || b > r || fit) return;
  int mid = (b + e) >> 1;
  Update(node << 1, b, mid, l, r, mul, add);
  Update((node << 1) + 1, mid + 1, e, l, r, mul, add);
  tree[node].Merge(tree[node << 1], tree[(node << 1) + 1]);
}

uint32_t Query(int node, int b, int e, int l, int r) {
  Push(node, b, e);
  if (l > e || b > r) return 0;
  if (l <= b && e <= r) return tree[node].val;
  int mid = (b + e) >> 1;
  return Query(node << 1, b, mid, l, r) + Query((node << 1) + 1, mid + 1, e, l, r);
}

vector<int> edges[500001];
int par[500001], depth[500001], heavy[500001], head[500001], in[500001], out[500001];
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
  head[cur] = h, in[cur] = ++idx;
  if (heavy[cur]) Decompose(heavy[cur], h);
  for (auto nxt : edges[cur]) {
    if (nxt == par[cur] || nxt == heavy[cur]) continue;
    Decompose(nxt, nxt);
  }
  out[cur] = idx;
}

vector<pair<int, int>> GetPath(int u, int v) {
  vector<pair<int, int>> res;
  while (head[u] != head[v]) {
    int hu = head[u], hv = head[v];
    if (depth[hu] > depth[hv]) {
      res.push_back({in[hu], in[u]});
      u = par[head[u]];
    } else {
      res.push_back({in[hv], in[v]});
      v = par[head[v]];
    }
  }
  if (depth[u] > depth[v]) swap(u, v);
  res.push_back({in[u], in[v]});
  return res;
}

void UpdatePath(int u, int v, uint32_t mul, uint32_t add) {
  auto path = GetPath(u, v);
  for (auto [l, r] : path) {
    Update(1, 0, kMax - 1, l, r, mul, add);
  }
}

uint32_t QueryPath(int u, int v) {
  uint32_t res = 0;
  auto path = GetPath(u, v);
  for (auto [l, r] : path) {
    res += Query(1, 0, kMax - 1, l, r);
  }
  return res;
}

void UpdateSubtree(int r, uint32_t mul, uint32_t add) {
  Update(1, 0, kMax - 1, in[r], out[r], mul, add);
}

uint32_t QuerySubtree(int r) {
  return Query(1, 0, kMax - 1, in[r], out[r]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  Traverse(1);
  Decompose(1, 1);

  while (q--) {
    int cmd;
    cin >> cmd;
    switch (cmd) {
      case 1: {
        int x, v;
        cin >> x >> v;
        UpdateSubtree(x, 1, v);
      } break;

      case 2: {
        int x, y, v;
        cin >> x >> y >> v;
        UpdatePath(x, y, 1, v);
      } break;

      case 3: {
        int x, v;
        cin >> x >> v;
        UpdateSubtree(x, v, 0);
      } break;

      case 4: {
        int x, y, v;
        cin >> x >> y >> v;
        UpdatePath(x, y, v, 0);
      } break;

      case 5: {
        int x;
        cin >> x;
        cout << QuerySubtree(x) << "\n";
      } break;

      case 6: {
        int x, y;
        cin >> x >> y;
        cout << QueryPath(x, y) << "\n";
      } break;
    }
  }

  return 0;
}
