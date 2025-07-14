// Title : Robotic Sort
// Link  : https://www.acmicpc.net/problem/3444 
// Time  : 400 ms
// Memory: 7604 KB

#include <bits/stdc++.h>

using namespace std;

struct LCT {
  struct Node {
    Node() : l(nullptr), r(nullptr), p(nullptr), rev(0), sz(1) {}

    Node *l, *r, *p;
    int rev, sz;
  };

  // LCT(int n) : nodes(n + 1) {}

  void Init(int n) {
    nodes.assign(n + 1, Node());
  }

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

  int GetDistance(int x) {
    int nsz = nodes.size();
    MakeRoot(&nodes[nsz - 2]);
    Access(&nodes[x]);
    return nodes[x].sz;
  }

  void Reverse(int u, int v) {
    int nsz = nodes.size();
    Node* st = &nodes[nsz - 2];
    Node* en = &nodes[nsz - 1];
    Node* x = GetNth(u);
    Node* y = GetNth(v);
    Node* xl = GetChild(st, x);
    Node* yr = GetChild(en, y);
    Cut(x, xl);
    Cut(y, yr);
    Link(x, yr);
    Link(y, xl);
  }

 private:
  bool IsRoot(Node* x) {
    return !x->p || (x->p->l != x && x->p->r != x);
  }

  void Pull(Node* x) {
    x->sz = 1;
    if (x->l) Push(x->l), x->sz += x->l->sz;
    if (x->r) Push(x->r), x->sz += x->r->sz;
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

  Node* GetNth(Node* x, int n) {
    Push(x);
    int sz = x->l ? x->l->sz : 0;
    if (n == sz + 1) return x;
    if (n <= sz) return GetNth(x->l, n);
    return GetNth(x->r, n - sz - 1);
  }

  Node* GetNth(int n) {
    int nsz = nodes.size();
    Node* st = &nodes[nsz - 2];
    Node* en = &nodes[nsz - 1];
    MakeRoot(st);
    Access(en);
    Node* x = GetNth(en, n + 1);
    Splay(x);
    return x;
  }

  vector<Node> nodes;
  vector<Node*> stk;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  LCT lct;
  vector<pair<int, int>> arr;

  int n;
  while (cin >> n && n) {
    arr.resize(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      arr[i] = {x, i + 1};
    }
    sort(arr.begin(), arr.end());

    int st = n + 1, en = n + 2;
    lct.Init(n + 2);
    for (int i = 1; i < n; i++) {
      lct.Link(i, i + 1);
    }
    lct.Link(st, 1), lct.Link(n, en);

    for (int i = 0; i < n; i++) {
      int idx = lct.GetDistance(arr[i].second) - 1;
      cout << idx << " ";
      lct.Reverse(i + 1, idx);
    }
    cout << "\n";
  }

  return 0;
}
