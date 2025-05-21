// Title : OR이 아니면? XOR
// Link  : https://www.acmicpc.net/problem/33901 
// Time  : 480 ms
// Memory: 205148 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : cnt(0), nxt{} {}

  int cnt;
  array<int, 2> nxt;
};

int nidx;
Node nodes[17000001];

void Insert(int x) {
  bitset<17> bits(x);

  Node* node = nodes;
  int idx = 17;
  while (idx--) {
    int bit = bits.test(idx);
    if (node->nxt[bit] == 0) node->nxt[bit] = ++nidx;
    node = nodes + node->nxt[bit];
    ++node->cnt;
  }
}

void Erase(int x) {
  bitset<17> bits(x);

  Node* node = nodes;
  int idx = 17;
  while (idx--) {
    int bit = bits.test(idx);
    auto nxt = nodes + node->nxt[bit];
    if (--nxt->cnt == 0) node->nxt[bit] = 0;
    node = nxt;
  }
}

int Query(int x) {
  bitset<17> bits(x);

  Node* node = nodes;
  int idx = 17;
  while (idx--) {
    int bit = bits.test(idx);
    if (node->nxt[bit] == 0) return 0;
    auto nxt = nodes + node->nxt[bit];
    node = nxt;
  }
  return node->cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int64_t cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i - m - 1 >= 0) Erase(arr[i - m - 1]);
    cnt += Query(arr[i] ^ k);
    Insert(arr[i]);
  }
  cout << cnt;

  return 0;
}