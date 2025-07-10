// Title : 비트 뒤집기와 쿼리
// Link  : https://www.acmicpc.net/problem/33585 
// Time  : 2164 ms
// Memory: 705148 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : cnt(0), nxt{} {}

  int cnt;
  int nxt[2];
};

Node nodes[60000002];
int root, idx;

void Insert(int x) {
  bitset<20> bits(x);
  Node* node = nodes + root;
  for (int i = 19; i >= 0; i--) {
    int b = bits.test(i);
    if (node->nxt[b] == 0) node->nxt[b] = ++idx;
    node = nodes + node->nxt[b];
    ++(node->cnt);
  }
}

int Count(int i) {
  return i ? nodes[i].cnt : 0;
}

int Query(int kth) {
  bitset<20> bits;
  Node* node = nodes + root;
  for (int i = 19; i >= 0; i--) {
    int cnt = Count(node->nxt[0]);
    if (cnt >= kth) {
      node = nodes + node->nxt[0];
    } else {
      kth -= cnt;
      node = nodes + node->nxt[1];
      bits.set(i);
    }
  }
  return bits.to_ulong();
}

int Merge(int lnode, int rnode) {
  if (lnode == 0) return rnode;
  if (rnode == 0) return lnode;

  nodes[lnode].cnt += nodes[rnode].cnt;
  nodes[lnode].nxt[0] = Merge(nodes[lnode].nxt[0], nodes[rnode].nxt[0]);
  nodes[lnode].nxt[1] = Merge(nodes[lnode].nxt[1], nodes[rnode].nxt[1]);
  return lnode;
}

pair<int, int> Split(int x, int node, int i) {
  if (node == 0) return {0, 0};
  if (i < 0) return {node, 0};
  if (x < 0) return {0, node};

  pair<int, int> res;
  if (x & (1 << i)) {
    auto [l, r] = Split(x, nodes[node].nxt[1], i - 1);
    ++idx;
    nodes[idx].nxt[0] = nodes[node].nxt[0];
    nodes[idx].nxt[1] = l;
    nodes[idx].cnt = Count(nodes[idx].nxt[0]) + Count(nodes[idx].nxt[1]);
    nodes[node].nxt[0] = 0;
    nodes[node].nxt[1] = r;
    nodes[node].cnt = Count(nodes[node].nxt[0]) + Count(nodes[node].nxt[1]);
    res = {idx, node};
  } else {
    auto [l, r] = Split(x, nodes[node].nxt[0], i - 1);
    ++idx;
    nodes[idx].nxt[0] = r;
    nodes[idx].nxt[1] = nodes[node].nxt[1];
    nodes[idx].cnt = Count(nodes[idx].nxt[0]) + Count(nodes[idx].nxt[1]);
    nodes[node].nxt[0] = l;
    nodes[node].nxt[1] = 0;
    nodes[node].cnt = Count(nodes[node].nxt[0]) + Count(nodes[node].nxt[1]);
    res = {node, idx};
  }
  return res;
}

void Flip(int node, int k, int i) {
  if (!node) return;
  if (k == i) {
    swap(nodes[node].nxt[0], nodes[node].nxt[1]);
    return;
  }
  Flip(nodes[node].nxt[0], k, i - 1);
  Flip(nodes[node].nxt[1], k, i - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  root = ++idx;

  int n, q;
  cin >> n >> q;
  while (n--) {
    int x;
    cin >> x;
    Insert(x);
  }

  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int l, r, k;
      cin >> l >> r >> k;
      auto [ls, mrs] = Split(l - 1, root, 19);
      auto [ms, rs] = Split(r, mrs, 19);
      Flip(ms, k, 19);
      root = Merge(Merge(ls, ms), rs);
    } else {
      int k;
      cin >> k;
      cout << Query(k) << "\n";
    }
  }

  return 0;
}
