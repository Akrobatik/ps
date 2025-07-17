// Title : 안전한 비상연락망
// Link  : https://www.acmicpc.net/problem/10169 
// Time  : 900 ms
// Memory: 22080 KB

#include <bits/stdc++.h>

using namespace std;

struct LCT {
  struct Node {
    Node() : l(nullptr), r(nullptr), p(nullptr), rev(0), val(0), maxx(0), midx(0), minn(INT_MAX), lazy(INT_MAX) {}

    Node *l, *r, *p;
    int rev;
    int val, maxx, midx;
    int minn, lazy;
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

  void SetLazy(int u, int v, int w) {
    MakeRoot(&nodes[u]);
    Access(&nodes[v]);
    nodes[v].minn = min<int>(nodes[v].minn, w);
    nodes[v].lazy = min<int>(nodes[v].lazy, w);
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
    return {nodes[v].maxx, nodes[v].midx};
  }

  int QueryMin(int x) {
    Access(&nodes[x]);
    return nodes[x].minn;
  }

 private:
  bool IsRoot(Node* x) {
    return !x->p || (x->p->l != x && x->p->r != x);
  }

  void Pull(Node* x) {
    x->maxx = x->val;
    x->midx = x - nodes.data();
    if (x->l) {
      Push(x->l);
      if (x->maxx < x->l->maxx) x->maxx = x->l->maxx, x->midx = x->l->midx;
    }
    if (x->r) {
      Push(x->r);
      if (x->maxx < x->r->maxx) x->maxx = x->r->maxx, x->midx = x->r->midx;
    }
  }

  void Push(Node* x) {
    if (!x) return;

    if (x->rev) {
      swap(x->l, x->r);
      if (x->l) x->l->rev ^= 1;
      if (x->r) x->r->rev ^= 1;
      x->rev = 0;
    }

    if (x->lazy < INT_MAX) {
      if (x->l) {
        x->l->minn = min<int>(x->l->minn, x->lazy);
        x->l->lazy = min<int>(x->l->lazy, x->lazy);
      }
      if (x->r) {
        x->r->minn = min<int>(x->r->minn, x->lazy);
        x->r->lazy = min<int>(x->r->lazy, x->lazy);
      }
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

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  LCT lct(n + m);
  vector<tup> arr(m);
  for (auto& [u, v, w] : arr) cin >> u >> v >> w;

  int64_t sum = 0;
  vector<bool> used(m);
  for (int i = 0; i < m; i++) {
    auto [u, v, w] = arr[i];
    lct.Set(i + n + 1, w);
    if (lct.IsConnected(u, v)) {
      auto [maxx, midx] = lct.QueryMax(u, v);
      if (maxx <= w) continue;

      auto [uu, vv, ww] = arr[midx - n - 1];
      lct.Cut(uu, midx);
      lct.Cut(midx, vv);
      sum -= ww;
      used[midx - n - 1] = false;
    }
    lct.Link(u, i + n + 1);
    lct.Link(i + n + 1, v);
    sum += w;
    used[i] = true;
  }

  vector<int64_t> ans(m, INT64_MAX);
  vector<int> cands;
  cands.reserve(n - 1);
  for (int i = 0; i < m; i++) {
    auto [u, v, w] = arr[i];
    if (!used[i]) {
      ans[i] = sum;
      lct.SetLazy(u, v, w);
    } else {
      cands.push_back(i);
    }
  }

  for (auto i : cands) {
    int minn = lct.QueryMin(i + n + 1);
    if (minn != INT_MAX) ans[i] = min<int64_t>(ans[i], sum - get<2>(arr[i]) + minn);
  }

  for (auto e : ans) {
    cout << (e != INT64_MAX ? e : -1) << "\n";
  }

  return 0;
}
