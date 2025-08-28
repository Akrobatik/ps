// Title : mex
// Link  : https://www.acmicpc.net/problem/16902 
// Time  : 180 ms
// Memory: 66476 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 3e5;
constexpr int kBits = 18;

struct Node {
  Node() : cnt(0), nxt{} {}

  int cnt;
  int nxt[2];
};

Node nodes[kMax * kBits + 1];
int nidx, lazy;

void Insert(int x) {
  bitset<32> bits(x);
  Node* node = nodes;
  for (int i = kBits; i >= 0; i--) {
    int b = bits.test(i);
    if (!node->nxt[b]) node->nxt[b] = ++nidx;
    node = nodes + node->nxt[b];
    ++node->cnt;
  }
}

int Count(int i) {
  return i ? nodes[i].cnt : 0;
}

int Mex() {
  int res = 0;
  Node* node = nodes;
  for (int i = kBits; i >= 0; i--) {
    int m = 1 << i;
    int b = (lazy & m) >> i;
    if (m != Count(node->nxt[b])) {
      if (!node->nxt[b]) return res;
      node = nodes + node->nxt[b];
    } else {
      res |= m;
      node = nodes + node->nxt[b ^ 1];
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());

  for (auto e : arr) {
    Insert(e);
  }

  while (m--) {
    int x;
    cin >> x;
    lazy ^= x;
    cout << Mex() << "\n";
  }

  return 0;
}
