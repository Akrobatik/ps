// Title : XOR
// Link  : https://www.acmicpc.net/problem/12844 
// Time  : 472 ms
// Memory: 10212 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 19;

int tree[kMax << 1], lazy[kMax << 1];

void Push(int node, int b, int e) {
  if (!lazy[node]) return;

  if (b != e) {
    lazy[node << 1] ^= lazy[node];
    lazy[(node << 1) + 1] ^= lazy[node];
  } else {
    tree[node] ^= lazy[node];
  }
  lazy[node] = 0;
}

void Update(int l, int r, int x, int node = 1, int b = 0, int e = kMax - 1) {
  bool fit = (l <= b && e <= r);
  if (fit) lazy[node] ^= x;
  Push(node, b, e);
  if (l > e || b > r || fit) return;
  int mid = (b + e) >> 1;
  Update(l, r, x, node << 1, b, mid);
  Update(l, r, x, (node << 1) + 1, mid + 1, e);
  tree[node] = tree[node << 1] ^ tree[(node << 1) + 1];
}

int Query(int l, int r, int node = 1, int b = 0, int e = kMax - 1) {
  Push(node, b, e);
  if (l > e || b > r) return 0;
  if (l <= b && e <= r) return tree[node];
  int mid = (b + e) >> 1;
  return Query(l, r, node << 1, b, mid) ^ Query(l, r, (node << 1) + 1, mid + 1, e);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int node = i + kMax;
    while (node) tree[node] ^= x, node >>= 1;
  }

  int m;
  cin >> m;
  while (m--) {
    char op;
    cin >> op;
    if (op == '1') {
      int i, j, k;
      cin >> i >> j >> k;
      Update(i, j, k);
    } else {
      int i, j;
      cin >> i >> j;
      cout << Query(i, j) << "\n";
    }
  }

  return 0;
}
