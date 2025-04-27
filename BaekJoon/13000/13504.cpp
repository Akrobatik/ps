// Title : XOR 합
// Link  : https://www.acmicpc.net/problem/13504 
// Time  : 500 ms
// Memory: 38348 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : cnt(0), nxt{} {}

  int cnt;
  array<int, 2> nxt;
};

int ans, nidx;
Node nodes[3100032];

void Insert(int x) {
  bitset<31> bits(x);

  Node* node = nodes;
  int idx = 31;
  while (idx--) {
    int bit = bits.test(idx);
    if (node->nxt[bit] == 0) node->nxt[bit] = ++nidx;
    node = nodes + node->nxt[bit];
    ++node->cnt;
  }
}

void Query(int x) {
  int res = 0;
  bitset<31> bits(x);

  Node* node = nodes;
  int idx = 31, mask = 1 << 30, maxx = INT_MAX;
  while (idx--) {
    int bit = bits.test(idx);
    if (node->nxt[bit ^ 1]) {
      res |= mask;
      node = nodes + node->nxt[bit ^ 1];
    } else {
      maxx ^= mask;
      node = nodes + node->nxt[bit];
    }
    if (maxx <= ans) return;
    mask >>= 1;
  }
  ans = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = 0;
    Insert(x);
    while (n--) {
      int y;
      cin >> y;
      x ^= y;
      Query(x);
      Insert(x);
    }
    cout << ans << "\n";

    memset(nodes, 0, sizeof(Node) * nidx);
    ans = nidx = 0;
  }

  return 0;
}
