// Title : Halcyon
// Link  : https://www.acmicpc.net/problem/34655 
// Time  : 1560 ms
// Memory: 32312 KB

#include <bits/stdc++.h>

using namespace std;

struct LCT {
  struct Node {
    Node() : l(nullptr), r(nullptr), p(nullptr), rev(0), val{}, maxx{} {}

    Node *l, *r, *p;
    int rev;
    pair<int, int> val, maxx;
  };

  LCT(int n) : nodes(n + 1) {}

  void MakeRoot(int x) {
    MakeRoot(&nodes[x]);
  }

  void Set(int x, int w, int id) {
    Access(&nodes[x]);
    nodes[x].val = {w, id};
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

  pair<int, int> Query(int u, int v) {
    MakeRoot(&nodes[u]);
    Access(&nodes[v]);
    return nodes[v].maxx;
  }

 private:
  bool IsRoot(Node* x) {
    return !x->p || (x->p->l != x && x->p->r != x);
  }

  void Pull(Node* x) {
    x->maxx = x->val;
    if (x->l) x->maxx = max<pair<int, int>>(x->maxx, x->l->maxx);
    if (x->r) x->maxx = max<pair<int, int>>(x->maxx, x->r->maxx);
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

  int n;
  cin >> n;
  int m = (n << 1) - 1;

  int64_t sum = 0;
  vector<tup> arr(n), brr(n);
  for (int i = 1; i < n; i++) {
    auto& [u, v, w] = arr[i];
    cin >> u >> v >> w;
  }
  for (int i = 1; i < n; i++) {
    auto& [u, v, w] = brr[i];
    cin >> u >> v >> w;
    sum += w;
  }

  LCT lct(m);
  for (int i = 1; i < n; i++) {
    auto [bu, bv, bw] = brr[i];
    int idx = i + n;
    lct.Set(idx, bw, i);
    lct.Link(bu, idx);
    lct.Link(idx, bv);
  }

  sort(arr.begin() + 1, arr.end(), [&](const tup& lhs, const tup& rhs) {
    return get<2>(lhs) < get<2>(rhs);
  });

  vector<int> dt(n);
  for (int i = 1; i < n; i++) {
    auto [au, av, aw] = arr[i];
    auto [mw, mi] = lct.Query(au, av);
    auto [bu, bv, bw] = brr[mi];
    int idx = mi + n;
    lct.Cut(bu, idx);
    lct.Cut(idx, bv);
    lct.Link(au, av);
    dt[i] = aw - mw;
  }
  sort(dt.begin() + 1, dt.end());

  cout << sum << "\n";
  for (int i = 1; i < n; i++) {
    sum += dt[i];
    cout << sum << "\n";
  }

  return 0;
}