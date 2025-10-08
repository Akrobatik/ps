// Title : 슥삭슥삭 나무자르기
// Link  : https://www.acmicpc.net/problem/30092 
// Time  : 2080 ms
// Memory: 14604 KB

#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

struct LCT {
  struct Node {
    Node() : l(nullptr), r(nullptr), p(nullptr), rev(0), type(0), tsum(0), val(0), sum(0), lazy(-1) {}

    Node *l, *r, *p;
    int rev;
    int type, tsum, val, sum, lazy;
  };

  LCT(int n) : nodes(n + 1) {}

  void MakeRoot(int x) {
    MakeRoot(&nodes[x]);
  }

  void Set(int x, int t) {
    Access(&nodes[x]);
    nodes[x].type = t;
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

  void Update(int u, int v, int x) {
    MakeRoot(&nodes[u]);
    Access(&nodes[v]);
    Apply(&nodes[v], x);
  }

  int Query(int u, int v) {
    MakeRoot(&nodes[u]);
    Access(&nodes[v]);
    return nodes[v].sum;
  }

 private:
  bool IsRoot(Node* x) {
    return !x->p || (x->p->l != x && x->p->r != x);
  }

  void Apply(Node* x, int lzy) {
    x->lazy = lzy;
    if (x->type) x->val = lzy;
    x->sum = lzy * x->tsum;
  }

  void Pull(Node* x) {
    if (x->l) Push(x->l);
    if (x->r) Push(x->r);

    x->tsum = x->type;
    x->sum = x->val;
    if (x->l) x->tsum += x->l->tsum, x->sum += x->l->sum;
    if (x->r) x->tsum += x->r->tsum, x->sum += x->r->sum;
  }

  void Push(Node* x) {
    if (!x) return;

    if (x->rev) {
      swap(x->l, x->r);
      if (x->l) x->l->rev ^= 1;
      if (x->r) x->r->rev ^= 1;
      x->rev = 0;
    }

    if (x->lazy != -1) {
      if (x->l) Apply(x->l, x->lazy);
      if (x->r) Apply(x->r, x->lazy);
      x->lazy = -1;
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

  int n, q;
  cin >> n >> q;

  LCT lct(n << 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    int x = n + i;
    lct.Set(x, 1);
    lct.Link(u, x);
    lct.Link(x, v);
  }

  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    lct.Update(a, b, 1);
    cout << (lct.Query(c, d) > 0 ? "NO\n" : "YES\n");
    lct.Update(a, b, 0);
  }

  return 0;
}