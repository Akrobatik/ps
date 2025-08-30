// Title : Do use segment tree
// Link  : https://www.acmicpc.net/problem/22487 
// Time  : 636 ms
// Memory: 16104 KB

#include <bits/stdc++.h>

using namespace std;

struct LCT {
  struct Node {
    Node() : l(nullptr), r(nullptr), p(nullptr), rev(0), sz(1), val(0), lazy(INT_MAX), maxx(0), fwd(0), bwd(0), sum(0) {}

    Node *l, *r, *p;
    int rev, sz;
    int val, lazy;
    int64_t maxx, fwd, bwd, sum;
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

  void UpdatePath(int u, int v, int w) {
    MakeRoot(&nodes[u]);
    Access(&nodes[v]);
    Apply(&nodes[v], w);
  }

  int64_t Query(int u, int v) {
    MakeRoot(&nodes[u]);
    Access(&nodes[v]);
    return nodes[v].maxx;
  }

 private:
  bool IsRoot(Node* x) {
    return !x->p || (x->p->l != x && x->p->r != x);
  }

  void Apply(Node* x, int lzy) {
    x->val = x->lazy = lzy;
    x->sum = (int64_t)lzy * x->sz;
    if (x->sum > 0) {
      x->maxx = x->fwd = x->bwd = x->sum;
    } else {
      x->maxx = x->fwd = x->bwd = x->val;
    }
  }

  void Pull(Node* x) {
    if (x->l) Push(x->l);
    if (x->r) Push(x->r);

    x->sz = 1;
    x->maxx = x->fwd = x->bwd = x->sum = x->val;

    for (auto [l, r] : {pair<Node*, Node*>{x->l, x}, pair<Node*, Node*>{x, x->r}}) {
      if (l == nullptr || r == nullptr) continue;

      int sz = l->sz + r->sz;
      int64_t maxx = max<int64_t>({l->maxx, r->maxx, l->bwd + r->fwd});
      int64_t fwd = max<int64_t>(l->fwd, l->sum + r->fwd);
      int64_t bwd = max<int64_t>(r->bwd, r->sum + l->bwd);
      int64_t sum = l->sum + r->sum;
      x->sz = sz;
      x->maxx = maxx;
      x->fwd = fwd;
      x->bwd = bwd;
      x->sum = sum;
    }
  }

  void Push(Node* x) {
    if (!x) return;

    if (x->rev) {
      swap(x->l, x->r);
      swap(x->fwd, x->bwd);
      if (x->l) x->l->rev ^= 1;
      if (x->r) x->r->rev ^= 1;
      x->rev = 0;
    }

    if (x->lazy != INT_MAX) {
      if (x->l) Apply(x->l, x->lazy);
      if (x->r) Apply(x->r, x->lazy);
      x->lazy = INT_MAX;
    }
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  LCT lct(n);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    lct.Set(i, x);
  }

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    lct.Link(u, v);
  }

  while (m--) {
    int cmd, a, b, c;
    cin >> cmd >> a >> b >> c;
    if (cmd == 1) {
      lct.UpdatePath(a, b, c);
    } else {
      cout << lct.Query(a, b) << "\n";
    }
  }

  return 0;
}
