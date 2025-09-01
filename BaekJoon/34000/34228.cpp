// Title : 턴제 전략 XOR 게임
// Link  : https://www.acmicpc.net/problem/34228 
// Time  : 176 ms
// Memory: 73116 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 3e5;
constexpr int kBits = 30;

struct Node {
  Node() : nxt{} {}

  int nxt[2];
};

Node nodes[kMax * kBits + 1];
int nidx;

void Insert(int x) {
  bitset<32> bits(x);
  Node* node = nodes;
  for (int i = kBits - 1; i >= 0; i--) {
    int b = bits.test(i);
    if (node->nxt[b] == 0) node->nxt[b] = ++nidx;
    node = nodes + node->nxt[b];
  }
}

int Query(int x) {
  int res = 0;
  bitset<32> bits(x);
  Node* node = nodes;
  for (int i = kBits - 1; i >= 0; i--) {
    int b = bits.test(i);
    if (node->nxt[b] == 0) {
      b ^= 1;
      res |= (1 << i);
    }
    node = nodes + node->nxt[b];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int key = 0;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e, key ^= e;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    key ^= x;
    Insert(x);
  }

  int maxx = 0;
  for (auto e : arr) {
    int cur = Query(e ^ key);
    maxx = max<int>(maxx, cur);
  }
  cout << maxx;

  return 0;
}
