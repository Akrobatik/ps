// Title : 트리와 쿼리 2
// Link  : https://www.acmicpc.net/problem/13511 
// Time  : 372 ms
// Memory: 14628 KB

#include <bits/stdc++.h>

using namespace std;

struct LCT {
  struct Node {
    Node() : l(nullptr), r(nullptr), p(nullptr), sz(1), sum(1), w(0), ws(0), rev(0) {}

    Node *l, *r, *p;
    int sz, sum, rev;
    int64_t w, ws;
  };

  LCT(int n) : nodes(n + 1) {}

  void MakeRoot(int x) {
    MakeRoot(&nodes[x]);
  }

  // set node value for DP
  void Set(int x, int w) {
    Access(&nodes[x]);
    nodes[x].sz = 1;
    nodes[x].w = w;
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

  int GetLCA(int u, int v) {
    return GetLCA(&nodes[u], &nodes[v]) - nodes.data();
  }

  int GetDistance(int u, int v) {
    MakeRoot(u);
    Access(&nodes[v]);
    return nodes[v].sum - 1;
  }

  int GetNth(int u, int v, int n) {
    MakeRoot(u);
    Access(&nodes[v]);
    Node* x = &nodes[v];
    if (n < 1 || n > x->sum) return 0;
    Node* y = GetNth(x, n);
    Splay(y);
    return y - nodes.data();
  }

  int64_t GetWSum(int u, int v) {
    MakeRoot(u);
    Access(&nodes[v]);
    return nodes[v].ws;
  }

 private:
  bool IsRoot(Node* x) {
    return !x->p || (x->p->l != x && x->p->r != x);
  }

  // lazy propagation
  void Pull(Node* x) {
    x->sum = x->sz;
    x->ws = x->w;
    if (x->l) x->sum += x->l->sum, x->ws += x->l->ws;
    if (x->r) x->sum += x->r->sum, x->ws += x->r->ws;
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
  }

  void Link(Node* u, Node* v) {
    MakeRoot(u);
    if (Access(v) != u) u->p = v;
  }

  void Cut(Node* x) {
    Access(x);
    x->l->p = nullptr;
    x->l = nullptr;
    Pull(x);
  }

  void Cut(Node* u, Node* v) {
    MakeRoot(u);
    Access(v);
    if (v->l == u) v->l = u->p = nullptr;
    Pull(v);
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

  Node* GetNth(Node* x, int n) {
    Push(x);
    int sz = x->l ? x->l->sum : 0;
    if (n == sz + 1) return x;
    if (n <= sz) return GetNth(x->l, n);
    return GetNth(x->r, n - sz - 1);
  }

  vector<Node> nodes;
  vector<Node*> stk;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  LCT lct(n << 1);
  for (int i = 1; i < n; i++) {
    int u, v, w, x = i + n;
    cin >> u >> v >> w;
    lct.Set(x, w);
    lct.Link(u, x);
    lct.Link(v, x);
  }

  int q;
  cin >> q;
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int u, v;
      cin >> u >> v;
      cout << lct.GetWSum(u, v) << "\n";
    } else {
      int u, v, k;
      cin >> u >> v >> k;
      cout << lct.GetNth(u, v, (k << 1) - 1) << "\n";
    }
  }

  return 0;
}
