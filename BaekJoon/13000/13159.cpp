// Title : 배열
// Link  : https://www.acmicpc.net/problem/13159 
// Time  : 852 ms
// Memory: 27876 KB

#include <bits/stdc++.h>

using namespace std;

struct LCT {
  struct Node {
    Node() : l(nullptr), r(nullptr), p(nullptr), rev(0), sz(0), val(0), minn(0), maxx(0), sum(0) {}

    Node *l, *r, *p;
    int rev;
    int sz;
    int val, minn, maxx;
    int64_t sum;
  };

  LCT(int n) : nodes(n + 1) {}

  void MakeRoot(int x) {
    MakeRoot(&nodes[x]);
  }

  void Set(int x, int v) {
    Access(&nodes[x]);
    nodes[x].val = v;
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

  void Shift(int u, int v, int n) {
    int m = v - u + 1;
    n %= m;
    if (n < 0) n += m;
    if (n == 0) return;
    n = m - n;

    int nsz = nodes.size();
    Node* st = &nodes[nsz - 2];
    Node* en = &nodes[nsz - 1];

    Node* x = GetNth(u);
    Node* y = GetNth(v);
    Node* mr = GetNth(u + n);
    Node* xl = GetChild(st, x);
    Node* yr = GetChild(en, y);
    Node* ml = GetChild(st, mr);
    Cut(x, xl);
    Cut(y, yr);
    Cut(ml, mr);
    Link(mr, xl);
    Link(x, y);
    Link(ml, yr);
  }

  tuple<int, int, int64_t> Query(int u, int v) {
    Node* x = GetNth(u);
    Node* y = GetNth(v);
    MakeRoot(x);
    Access(y);
    return {y->minn, y->maxx, y->sum};
  }

  int GetNthValue(int n) {
    return GetNth(n)->val;
  }

  int GetValueNth(int v) {
    int nsz = nodes.size();
    Node* st = &nodes[nsz - 2];
    Node* en = &nodes[v];
    MakeRoot(st);
    Access(en);
    return en->sz - 1;
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
    if (x != st && x != en) out.push_back(x->val);
    DFS(x->r, st, en, out);
  }

 private:
  bool IsRoot(Node* x) {
    return !x->p || (x->p->l != x && x->p->r != x);
  }

  void Pull(Node* x) {
    x->sz = 1;
    x->minn = x->maxx = x->sum = x->val;

    if (x->l) {
      Push(x->l);
      x->sz += x->l->sz;
      x->sum += x->l->sum;
      x->minn = min<int>(x->minn, x->l->minn);
      x->maxx = max<int>(x->maxx, x->l->maxx);
    }
    if (x->r) {
      Push(x->r);
      x->sz += x->r->sz;
      x->sum += x->r->sum;
      x->minn = min<int>(x->minn, x->r->minn);
      x->maxx = max<int>(x->maxx, x->r->maxx);
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

  int n, q;
  cin >> n >> q;

  LCT lct(n + 2);
  for (int i = 1; i <= n; i++) {
    lct.Set(i, i);
  }

  for (int i = 1; i < n; i++) {
    lct.Link(i, i + 1);
  }
  lct.Link(1, n + 1);
  lct.Link(n, n + 2);

  while (q--) {
    int cmd;
    cin >> cmd;
    switch (cmd) {
      case 1: {
        int l, r;
        cin >> l >> r;
        auto [minn, maxx, sum] = lct.Query(l, r);
        lct.Reverse(l, r);
        cout << minn << " " << maxx << " " << sum << "\n";
      } break;

      case 2: {
        int l, r, x;
        cin >> l >> r >> x;
        auto [minn, maxx, sum] = lct.Query(l, r);
        lct.Shift(l, r, x);
        cout << minn << " " << maxx << " " << sum << "\n";
      } break;

      case 3: {
        int x;
        cin >> x;
        cout << lct.GetNthValue(x) << "\n";
      } break;

      case 4: {
        int x;
        cin >> x;
        cout << lct.GetValueNth(x) << "\n";
      } break;
    }
  }
  lct.Print();

  return 0;
}
