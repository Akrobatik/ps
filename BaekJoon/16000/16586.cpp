// Title : Linked List
// Link  : https://www.acmicpc.net/problem/16586 
// Time  : 340 ms
// Memory: 7604 KB

#include <bits/stdc++.h>

using namespace std;

struct LCT {
  struct Node {
    Node() : l(nullptr), r(nullptr), p(nullptr), rev(0), sz(0) {}

    Node *l, *r, *p;
    int rev;
    int sz;
  };

  LCT(int n) : nodes(n + 1) {}

  void MakeRoot(int x) {
    MakeRoot(&nodes[x]);
  }

  void Set(int x) {
    Access(&nodes[x]);
    //
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

  int GetDistance(int u, int v) {
    MakeRoot(&nodes[u]);
    Access(&nodes[v]);
    return nodes[v].sz - 1;
  }

  void Print() {
    int nsz = nodes.size();
    Node* st = &nodes[nsz - 2];
    Node* en = &nodes[nsz - 1];
    MakeRoot(st);
    Access(en);

    vector<int> arr;
    arr.reserve(nsz - 3);
    DFS(en, st, en, arr);
    for (auto e : arr) cout << e << " ";
    cout << "\n";
  }

  void DFS(Node* x, Node* st, Node* en, vector<int>& out) {
    if (!x) return;
    Push(x);
    DFS(x->l, st, en, out);
    if (x != st && x != en) out.push_back(x - nodes.data());
    DFS(x->r, st, en, out);
  }

 private:
  bool IsRoot(Node* x) {
    return !x->p || (x->p->l != x && x->p->r != x);
  }

  void Pull(Node* x) {
    x->sz = 1;
    if (x->l) x->sz += x->l->sz;
    if (x->r) x->sz += x->r->sz;
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  LCT lct(n + 2);
  vector<pair<int, int>> lr(n + 3);
  for (int i = 1; i < n; i++) {
    lct.Link(i, i + 1);
    lr[i] = {i - 1, i + 1};
  }
  lct.Link(1, n + 1);
  lct.Link(n, n + 2);
  lr[1] = {n + 1, 2};
  lr[n] = {n - 1, n + 2};
  lr[n + 1] = {0, 1};
  lr[n + 2] = {n, 0};

  while (q--) {
    int a, b;
    cin >> a >> b;

    int da = lct.GetDistance(n + 1, a);
    int db = lct.GetDistance(n + 1, b);
    if (da < db) {
      cout << db - da << "\n";
    } else {
      cout << db - da + 1 << "\n";
    }

    auto [la, ra] = lr[a];
    lr[la].second = ra;
    lr[ra].first = la;

    lct.Cut(la, a);
    lct.Cut(a, ra);
    lct.Link(la, ra);

    int rb = lr[b].second;
    lr[a] = {b, rb};
    lr[b].second = a;
    lr[rb].first = a;

    lct.Cut(b, rb);
    lct.Link(b, a);
    lct.Link(a, rb);
  }
  lct.Print();

  return 0;
}