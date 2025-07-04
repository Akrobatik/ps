// Title : 수열과 쿼리 15
// Link  : https://www.acmicpc.net/problem/14427 
// Time  : 36 ms
// Memory: 3044 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 17;
int tree[kMax << 1];

void Update(int i, int v) {
  int node = i + kMax;
  tree[node] = v;
  while (node >>= 1) tree[node] = min<int>(tree[node << 1], tree[(node << 1) + 1]);
}

int Query() {
  int node = 1;
  while (node < kMax) {
    if (tree[node] == tree[node << 1]) {
      node <<= 1;
    } else {
      node = (node << 1) + 1;
    }
  }
  return node - kMax;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  tree[kMax] = INT_MAX;
  for (int i = 1; i <= n; i++) {
    cin >> tree[i + kMax];
  }
  for (int i = n + 1; i < kMax; i++) {
    tree[i + kMax] = INT_MAX;
  }
  for (int i = kMax - 1; i; i--) {
    tree[i] = min<int>(tree[i << 1], tree[(i << 1) + 1]);
  }

  int m;
  cin >> m;
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int i, v;
      cin >> i >> v;
      Update(i, v);
    } else {
      cout << Query() << "\n";
    }
  }

  return 0;
}
