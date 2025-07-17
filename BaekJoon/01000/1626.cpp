// Title : 두 번째로 작은 스패닝 트리
// Link  : https://www.acmicpc.net/problem/1626 
// Time  : 868 ms
// Memory: 10040 KB

#include <bits/stdc++.h>

using namespace std;

struct LCT {
  struct Node {
    Node() : l(nullptr), r(nullptr), p(nullptr), rev(0), val(INT_MIN), maxx{INT_MIN, INT_MIN, INT_MIN, INT_MIN} {}

    Node *l, *r, *p;
    int rev;
    int val, maxx[4];
  };

  LCT(int n) : nodes(n + 1) {}

  void MakeRoot(int x) {
    MakeRoot(&nodes[x]);
  }

  void Set(int x, int w) {
    Access(&nodes[x]);
    nodes[x].val = w;
    Pull(&nodes[x]);
  }

  void Link(int u, int v) {
    Link(&nodes[u], &nodes[v]);
  }

  void Cut(int x) {
    Cut(&nodes[x]);
  }

  void Cut(int u, int v) {
    Cut(&nodes[u], &nodes[v]);
  }

  bool IsConnected(int u, int v) {
    return GetRoot(&nodes[u]) == GetRoot(&nodes[v]);
  }

  int GetParent(int x) {
    auto p = GetParent(&nodes[x]);
    return p ? p - nodes.data() : 0;
  }

  // v = ancestor of u
  // output: child of v, on u -> v path
  int GetChild(int u, int v) {
    auto p = GetChild(&nodes[u], &nodes[v]);
    return p ? p - nodes.data() : 0;
  }

  int GetLCA(int u, int v, int r = 0) {
    if (r) MakeRoot(&nodes[r]);
    return GetLCA(&nodes[u], &nodes[v]) - nodes.data();
  }

  pair<int, int> QueryMax(int u, int v) {
    MakeRoot(&nodes[u]);
    Access(&nodes[v]);
    return {nodes[v].maxx[0], nodes[v].maxx[1]};
  }

 private:
  bool IsRoot(Node* x) {
    return !x->p || (x->p->l != x && x->p->r != x);
  }

  void Pull(Node* x) {
    x->maxx[0] = x->val;
    x->maxx[1] = INT_MIN;
    for (auto c : {x->l, x->r}) {
      if (!c) continue;
      x->maxx[2] = c->maxx[0];
      x->maxx[3] = c->maxx[1];
      sort(x->maxx, x->maxx + 4, greater<int>());
      for (int i = unique(x->maxx, x->maxx + 4) - x->maxx; i < 4; i++) {
        x->maxx[i] = INT_MIN;
      }
    }
  }

  void Push(Node* x) {
    if (!x || !x->rev) return;
    swap(x->l, x->r);
    if (x->l) x->l->rev ^= 1;
    if (x->r) x->r->rev ^= 1;
    x->rev = 0;
  }

  void Rotate(Node* x) {
    Node *p = x->p, *g = p->p;
    Push(p);
    Push(x);
    bool r = (x == p->r);
    Node* b = (r ? x->l : x->r);
    if (!IsRoot(p)) (p == g->r ? g->r : g->l) = x;
    x->p = g;
    (r ? x->l : x->r) = p;
    p->p = x;
    (r ? p->r : p->l) = b;
    if (b) b->p = p;
    Pull(p);
    Pull(x);
  }

  void Splay(Node* x) {
    Node* y = x;
    do stk.push_back(y);
    while (!IsRoot(y) && (y = y->p));
    while (!stk.empty()) Push(stk.back()), stk.pop_back();

    while (!IsRoot(x)) {
      Node *p = x->p, *g = p->p;
      if (!IsRoot(p)) {
        if ((p->l == x) != (g->l == p)) {
          Rotate(x);
        } else {
          Rotate(p);
        }
      }
      Rotate(x);
    }
  }

  Node* Access(Node* x) {
    Node* o = nullptr;
    for (Node* y = x; y; y = y->p) {
      Splay(y);
      y->r = o;
      Pull(y);
      o = y;
    }
    Splay(x);
    return o;
  }

  void MakeRoot(Node* x) {
    Access(x);
    x->rev ^= 1;
    Push(x);
  }

  void Link(Node* u, Node* v) {
    MakeRoot(u);
    if (Access(v) != u) u->p = v;
  }

  void Cut(Node* x) {
    Access(x);
    if (x->l) {
      x->l->p = nullptr;
      x->l = nullptr;
      Pull(x);
    }
  }

  void Cut(Node* u, Node* v) {
    MakeRoot(u);
    Access(v);
    if (v->l == u) {
      v->l->p = nullptr;
      v->l = nullptr;
      Pull(v);
    }
  }

  Node* GetRoot(Node* x) {
    Access(x);
    for (;;) {
      Push(x);
      if (!x->l) break;
      x = x->l;
    }
    Splay(x);
    return x;
  }

  Node* GetParent(Node* x) {
    Access(x);
    if (!x->l) return nullptr;

    x = x->l;
    Push(x);
    while (x->r) {
      x = x->r;
      Push(x);
    }
    Splay(x);
    return x;
  }

  Node* GetChild(Node* u, Node* v) {
    MakeRoot(v);
    Access(u);
    Splay(v);
    if (!v->r) return nullptr;

    Node* x = v->r;
    Push(x);
    while (x->l) {
      x = x->l;
      Push(x);
    }
    Splay(x);
    return x;
  }

  Node* GetLCA(Node* u, Node* v) {
    if (u == v) return u;
    Access(u);
    return Access(v);
  }

  vector<Node> nodes;
  vector<Node*> stk;
};

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<tup> arr;
  arr.reserve(m);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    if (u == v) continue;
    arr.push_back({u, v, w});
  }
  m = arr.size();

  sort(arr.begin(), arr.end(), [&](const tup& lhs, const tup& rhs) {
    return get<2>(lhs) < get<2>(rhs);
  });

  vector<int> memo(n + 1);
  iota(memo.begin(), memo.end(), 0);

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return false;
    memo[b] = a;
    return true;
  };

  int64_t sum = 0;
  int idx = n, rem = n - 1;
  vector<int> unused;
  unused.reserve(m);
  LCT lct(n * 2 - 1);
  for (int i = 0; i < m; i++) {
    auto [u, v, w] = arr[i];
    if (Union(u, v)) {
      sum += w;
      ++idx;
      --rem;
      lct.Set(idx, w);
      lct.Link(u, idx);
      lct.Link(idx, v);
    } else {
      unused.push_back(i);
    }
  }

  if (rem || unused.empty()) {
    cout << "-1";
    return 0;
  }

  int64_t ans = INT64_MAX;
  for (auto i : unused) {
    auto [u, v, w] = arr[i];
    auto [m1, m2] = lct.QueryMax(u, v);
    if (m1 != INT_MIN && w > m1) ans = min<int64_t>(ans, sum + w - m1);
    if (m2 != INT_MIN && w > m2) ans = min<int64_t>(ans, sum + w - m2);
  }
  cout << (ans != INT64_MAX ? ans : -1);

  return 0;
}
