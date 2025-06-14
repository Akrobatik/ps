// Title : 수열과 쿼리 31
// Link  : https://www.acmicpc.net/problem/17607 
// Time  : 252 ms
// Memory: 8360 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node(int v) : l(nullptr), r(nullptr), rev(0), pr(rand()), sz(1), val(v), fwd(v), bwd(v), maxx(v) {}

  Node *l, *r;
  int rev, pr, sz;
  int val, fwd, bwd, maxx;
};

void Pull(Node* x) {
  x->sz = 1;
  x->fwd = x->bwd = x->maxx = x->val;

  if (x->l) x->sz += x->l->sz;
  if (x->r) x->sz += x->r->sz;

  if (x->l && x->l->fwd == x->l->sz && x->val == 1) {
    x->fwd = x->l->fwd + 1 + (x->r ? x->r->fwd : 0);
  } else if (x->l) {
    x->fwd = x->l->fwd;
  } else if (x->val) {
    x->fwd = x->val + (x->r ? x->r->fwd : 0);
  }

  if (x->r && x->r->bwd == x->r->sz && x->val == 1) {
    x->bwd = x->r->bwd + 1 + (x->l ? x->l->bwd : 0);
  } else if (x->r) {
    x->bwd = x->r->bwd;
  } else if (x->val) {
    x->bwd = x->val + (x->l ? x->l->bwd : 0);
  }

  if (x->l) x->maxx = max<int>(x->maxx, x->l->maxx);
  if (x->r) x->maxx = max<int>(x->maxx, x->r->maxx);

  int mid = 0;
  if (x->val == 1) {
    mid = 1;
    if (x->l) mid += x->l->bwd;
    if (x->r) mid += x->r->fwd;
  }
  x->maxx = max<int>(x->maxx, mid);
}

void Apply(Node* x) {
  x->rev ^= 1;
  swap(x->l, x->r);
  swap(x->fwd, x->bwd);
}

void Push(Node* x) {
  if (!x->rev) return;
  if (x->l) Apply(x->l);
  if (x->r) Apply(x->r);
  x->rev = 0;
}

void Split(Node* x, int n, Node*& l, Node*& r) {
  if (!x) {
    l = r = nullptr;
    return;
  }

  Push(x);
  int lsz = (x->l ? x->l->sz : 0);
  if (lsz >= n) {
    Split(x->l, n, l, x->l);
    r = x;
  } else {
    Split(x->r, n - lsz - 1, x->r, r);
    l = x;
  }
  Pull(x);
}

Node* Merge(Node* l, Node* r) {
  if (!l || !r) return l ? l : r;

  Node* res;
  if (l->pr > r->pr) {
    Push(l);
    l->r = Merge(l->r, r);
    Pull(l);
    res = l;
  } else {
    Push(r);
    r->l = Merge(l, r->l);
    Pull(r);
    res = r;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  srand(time(nullptr));

  int n;
  cin >> n;
  Node* root = nullptr;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    root = Merge(root, new Node(v));
  }

  int m;
  cin >> m;
  while (m--) {
    int cmd, l, r;
    cin >> cmd >> l >> r;
    Node *lnode, *mnode, *rnode;
    Split(root, l - 1, lnode, mnode);
    Split(mnode, r - l + 1, mnode, rnode);
    if (cmd == 1) {
      Apply(mnode);
    } else {
      cout << mnode->maxx << "\n";
    }
    lnode = Merge(lnode, mnode);
    root = Merge(lnode, rnode);
  }

  return 0;
}
