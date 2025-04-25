// Title : 수열과 쿼리 20
// Link  : https://www.acmicpc.net/problem/16903 
// Time  : 132 ms
// Memory: 72332 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : cnt(0), nxt{} {}

  int cnt;
  array<int, 2> nxt;
};

int nidx;
Node nodes[6000031];

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

void Erase(int x) {
  bitset<30> bits(x);

  Node* node = nodes;
  int idx = 30;
  while (idx--) {
    int bit = bits.test(idx);
    auto nxt = nodes + node->nxt[bit];
    if (--nxt->cnt == 0) node->nxt[bit] = 0;
    node = nxt;
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

  Insert(0);

  int n;
  cin >> n;
  while (n--) {
    int op, x;
    cin >> op >> x;
    switch (op) {
      case 1: {
        Insert(x);
      } break;

      case 2: {
        Erase(x);
      } break;

      case 3: {
        cout << Query(x) << "\n";
      } break;
    }
  }

  return 0;
}
