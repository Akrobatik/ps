// Title : 트리와 쿼리 12
// Link  : https://www.acmicpc.net/problem/16912 
// Time  : 104 ms
// Memory: 61940 KB

#include <bits/stdc++.h>

using namespace std;

struct LCT {
  struct Node {
    Node() : l(nullptr), r(nullptr), p(nullptr), rev(0) {}

    Node *l, *r, *p;
    int rev;
  };

  LCT(int n) : nodes(n + 1) {}

  void MakeRoot(int x) {
    MakeRoot(&nodes[x]);
  }

  void Link(int u, int v) {
    Link(&nodes[u], &nodes[v]);
  }

  void Cut(int u, int v) {
    Cut(&nodes[u], &nodes[v]);
  }

  bool IsConnected(int u, int v) {
    return GetRoot(&nodes[u]) == GetRoot(&nodes[v]);
  }

  int GetLCA(int u, int v) {
    return GetLCA(&nodes[u], &nodes[v]) - nodes.data();
  }

 private:
  bool IsRoot(Node* x) {
    return !x->p || (x->p->l != x && x->p->r != x);
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

  void Cut(Node* u, Node* v) {
    MakeRoot(u);
    Access(v);
    if (v->l == u) v->l = u->p = nullptr;
  }

  Node* GetRoot(Node* x) {
    Access(x);
    while (x->l) x = x->l;
    Splay(x);
    return x;
  }

  Node* GetParent(Node* x) {
    Access(x);
    if (IsRoot(x)) return nullptr;
    for (x = x->l; x->r; x = x->r);
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

constexpr int kMax = 17;
constexpr int64_t kMask = (1ll << 32) - 1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<LCT> lct(kMax, n);
  unordered_map<int64_t, int> level;
  unordered_set<int64_t> pending[kMax];
  deque<int64_t> pending_dq[kMax];

  auto MakeKey = [](int64_t a, int64_t b) {
    return (a << 32) | b;
  };

  auto SplitKey = [](int64_t key) {
    int a = key >> 32, b = key & kMask;
    return make_pair(a, b);
  };

  auto Link = [&](int a, int b) {
    if (a > b) swap(a, b);
    auto key = MakeKey(a, b);
    level[key] = 0;
    if (lct[0].IsConnected(a, b)) {
      pending[0].insert(key);
      pending_dq[0].push_back(key);
    } else {
      lct[0].Link(a, b);
    }
  };

  auto Cut = [&](int a, int b) {
    if (a > b) swap(a, b);
    auto key = MakeKey(a, b);
    int lv = level[key];
    level.erase(key);

    if (pending[lv].erase(key)) return;

    lct[lv].Cut(a, b);
    for (int i = lv; i >= 0; i--) {
      int ndq = pending_dq[i].size();
      while (ndq--) {
        auto e = pending_dq[i].front();
        pending_dq[i].pop_front();

        if (!pending[i].contains(e)) continue;

        auto [u, v] = SplitKey(e);
        if (lct[i].IsConnected(u, v)) {
          pending_dq[i].push_back(e);
        } else {
          lct[i].Link(u, v);
          level[e] = i;
          pending[i].erase(e);
          return;
        }
      }
    }
  };

  auto IsConnected = [&](int a, int b) {
    return lct[0].IsConnected(a, b);
  };

  while (m--) {
    int cmd, a, b;
    cin >> cmd >> a >> b;
    if (cmd == 1) {
      Link(a, b);
    } else if (cmd == 2) {
      Cut(a, b);
    } else {
      cout << IsConnected(a, b) << "\n";
    }
  }

  return 0;
}
