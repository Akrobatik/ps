// Title : 트리와 쿼리 3
// Link  : https://www.acmicpc.net/problem/13512 
// Time  : 132 ms
// Memory: 7596 KB

#include <bits/stdc++.h>

using namespace std;

struct LCT {
  struct Node {
    Node() : l(nullptr), r(nullptr), p(nullptr), b(nullptr), ib(0), rev(0) {}

    Node *l, *r, *p, *b;
    int ib, rev;
  };

  LCT(int n) : nodes(n + 1) {}

  void MakeRoot(int x) {
    MakeRoot(&nodes[x]);
  }

  void ToggleColor(int x) {
    Access(&nodes[x]);
    nodes[x].ib ^= 1;
    Pull(&nodes[x]);
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

  int GetChild(int u, int v) {
    auto p = GetChild(&nodes[u], &nodes[v]);
    return p ? p - nodes.data() : 0;
  }

  int GetLCA(int u, int v) {
    return GetLCA(&nodes[u], &nodes[v]) - nodes.data();
  }

  int Query(int x) {
    MakeRoot(1);
    Node* cur = &nodes[x];
    Access(cur);
    Push(cur);

    while (cur) {
      Push(cur);
      if (cur->l && cur->l->b) {
        cur = cur->l;
      } else if (cur->ib) {
        return cur - nodes.data();
      } else {
        cur = cur->r;
      }
    }
    return -1;
  }

 private:
  bool IsRoot(Node* x) {
    return !x->p || (x->p->l != x && x->p->r != x);
  }

  // lazy propagation
  void Pull(Node* x) {
    x->b = nullptr;
    if (x->l && x->l->b) x->b = x->l->b;
    if (x->ib && !x->b) x->b = x;
    if (x->r && x->r->b && !x->b) x->b = x->r->b;
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

  vector<Node> nodes;
  vector<Node*> stk;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  LCT lct(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    lct.Link(u, v);
  }

  int m;
  cin >> m;
  while (m--) {
    int cmd, x;
    cin >> cmd >> x;
    if (cmd == 1) {
      lct.ToggleColor(x);
    } else {
      cout << lct.Query(x) << "\n";
    }
  }

  return 0;
}
