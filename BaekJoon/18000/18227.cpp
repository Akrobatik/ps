// Title : 성대나라의 물탱크
// Link  : https://www.acmicpc.net/problem/18227 
// Time  : 376 ms
// Memory: 26328 KB

#include <bits/stdc++.h>

using namespace std;

struct LCT {
  struct Node {
    Node() : l(nullptr), r(nullptr), p(nullptr), rev(0), val(0), add(0) {}

    Node *l, *r, *p;
    int rev;
    int64_t val, add;
  };

  LCT(int n) : nodes(n + 1) {}

  void MakeRoot(int x) {
    MakeRoot(&nodes[x]);
  }

  void Add(int x) {
    Access(&nodes[x]);
    ++nodes[x].add;
    Pull(&nodes[x]);
  }

  int64_t Query(int x) {
    Access(&nodes[x]);
    Splay(&nodes[x]);
    Push(&nodes[x]);
    return nodes[x].val;
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

  int GetLCA(int u, int v) {
    return GetLCA(&nodes[u], &nodes[v]) - nodes.data();
  }

 private:
  bool IsRoot(Node* x) {
    return !x->p || (x->p->l != x && x->p->r != x);
  }

  void Pull(Node* x) {
  }

  void Push(Node* x) {
    if (!x) return;
    if (x->rev) {
      swap(x->l, x->r);
      if (x->l) x->l->rev ^= 1;
      if (x->r) x->r->rev ^= 1;
      x->rev = 0;
    }
    if (x->add != 0) {
      x->val += x->add;
      if (x->l) x->l->add += x->add;
      if (x->r) x->r->add += x->add;
      x->add = 0;
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

vector<int> edges[200001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, root;
  cin >> n >> root;

  LCT lct(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  vector<int> depth(n + 1);
  queue<pair<int, int>> q;
  depth[root] = 1;
  q.push({root, 0});
  while (!q.empty()) {
    auto [cur, par] = q.front();
    q.pop();

    for (auto nxt : edges[cur]) {
      if (nxt == par) continue;
      depth[nxt] = depth[cur] + 1;
      lct.Link(nxt, cur);
      q.push({nxt, cur});
    }
  }

  int m;
  cin >> m;
  while (m--) {
    int cmd, x;
    cin >> cmd >> x;
    if (cmd == 1) {
      lct.Add(x);
    } else {
      cout << lct.Query(x) * depth[x] << "\n";
    }
  }

  return 0;
}
