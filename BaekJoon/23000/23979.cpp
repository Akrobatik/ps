// Title : 트리의 재구성
// Link  : https://www.acmicpc.net/problem/23979 
// Time  : 840 ms
// Memory: 17344 KB

#include <bits/stdc++.h>

using namespace std;

struct LCT {
  struct Node {
    Node() : l(nullptr), r(nullptr), p(nullptr), rev(0), w(0), id(0), sum(0), maxx{} {}

    Node *l, *r, *p;
    int rev;
    int w, id;
    int64_t sum;
    pair<int, int> maxx;
  };

  LCT(int n) : nodes(n + 1) {}

  void MakeRoot(int x) {
    MakeRoot(&nodes[x]);
  }

  void Set(int x, int w) {
    Access(&nodes[x]);
    nodes[x].w = w;
    nodes[x].id = x;
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

  int QueryMax(int u, int v) {
    MakeRoot(&nodes[u]);
    Access(&nodes[v]);
    return nodes[v].maxx.second;
  }

  int64_t QuerySum(int u, int v) {
    MakeRoot(&nodes[u]);
    Access(&nodes[v]);
    return nodes[v].sum;
  }

 private:
  bool IsRoot(Node* x) {
    return !x->p || (x->p->l != x && x->p->r != x);
  }

  void Pull(Node* x) {
    x->sum = x->w;
    x->maxx = {x->w, x->id};
    if (x->l) {
      x->sum += x->l->sum;
      x->maxx = max<pair<int, int>>(x->maxx, x->l->maxx);
    }
    if (x->r) {
      x->sum += x->r->sum;
      x->maxx = max<pair<int, int>>(x->maxx, x->r->maxx);
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

  vector<Node> nodes;
  vector<Node*> stk;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  LCT lct((n << 1) - 1);

  vector<tuple<int, int, int>> arr(n);

  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    arr[i] = {u, v, w};
    lct.Set(i + n, w);
    lct.Link(u, i + n);
    lct.Link(i + n, v);
  }

  while (q--) {
    int u, v, w, a, b;
    cin >> u >> v >> w >> a >> b;

    int id = lct.QueryMax(u, v);
    auto [ou, ov, ow] = arr[id - n];
    lct.Cut(ou, id);
    lct.Cut(id, ov);
    lct.Set(id, w);
    lct.Link(u, id);
    lct.Link(id, v);
    cout << lct.QuerySum(a, b) << "\n";
    lct.Cut(u, id);
    lct.Cut(id, v);
    lct.Set(id, ow);
    lct.Link(ou, id);
    lct.Link(id, ov);
  }

  return 0;
}
