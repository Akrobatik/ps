// Title : 최솟값
// Link  : https://www.acmicpc.net/problem/10868 
// Time  : 48 ms
// Memory: 3044 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 17;

int tree[kMax << 1];

int Get(int node) {
  int x = tree[node];
  return x ? x : INT_MAX;
}

int Query(int l, int r) {
  int res = INT_MAX;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = min<int>(res, Get(l++));
    if (r & 1) res = min<int>(res, Get(--r));
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int node = i + kMax;
    while (node && Get(node) > x) tree[node] = x, node >>= 1;
  }

  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << Query(l - 1, r - 1) << "\n";
  }

  return 0;
}
