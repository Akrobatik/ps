// Title : 두 수 XOR
// Link  : https://www.acmicpc.net/problem/13505 
// Time  : 72 ms
// Memory: 37176 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : cnt(0), nxt{} {}

  int cnt;
  array<int, 2> nxt;
};

int nidx;
Node nodes[3000001];

void Insert(int x) {
  bitset<30> bits(x);

  Node* node = nodes;
  int idx = 30;
  while (idx--) {
    int bit = bits.test(idx);
    if (node->nxt[bit] == 0) node->nxt[bit] = ++nidx;
    node = nodes + node->nxt[bit];
    ++node->cnt;
  }
}

int Query(int x) {
  int res = 0;
  bitset<30> bits(x);

  Node* node = nodes;
  int idx = 30, mask = 1 << 29;
  while (idx--) {
    int bit = bits.test(idx);
    if (node->nxt[bit ^ 1]) {
      res |= mask;
      node = nodes + node->nxt[bit ^ 1];
    } else {
      node = nodes + node->nxt[bit];
    }
    mask >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;
  Insert(x);
  int maxx = 0;
  while (--n) {
    cin >> x;
    maxx = max<int>(maxx, Query(x));
    Insert(x);
  }
  cout << maxx;

  return 0;
}
