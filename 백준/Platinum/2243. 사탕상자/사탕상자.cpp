#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1000000;
int tree[1 << 21];

void Update(int node, int b, int e, int idx, int v) {
  if (b == e) {
    tree[node] += v;
  } else {
    int mid = ((b + e) >> 1);
    if (idx <= mid) {
      Update(node << 1, b, mid, idx, v);
    } else {
      Update((node << 1) + 1, mid + 1, e, idx, v);
    }
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
  }
}

int Query(int node, int b, int e, int nth) {
  if (b == e) return b;
  int mid = ((b + e) >> 1);
  if (tree[node << 1] >= nth) return Query(node << 1, b, mid, nth);
  return Query((node << 1) + 1, mid + 1, e, nth - tree[node << 1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    int a, b, c;
    cin >> a >> b;
    if (a == 1) {
      int v = Query(1, 1, kMax, b);
      Update(1, 1, kMax, v, -1);
      cout << v << "\n";
    } else {
      cin >> c;
      Update(1, 1, kMax, b, c);
    }
  }

  return 0;
}
