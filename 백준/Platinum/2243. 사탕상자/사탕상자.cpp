#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = (1 << 20) - 1;
int tree[1 << 21];

void Update(int idx, int v) {
  int node = idx + kMax + 1;
  tree[node] += v;
  while (node >>= 1) tree[node] += v;
}

int Query(int nth) {
  int node = 1;
  int b = 0;
  int e = kMax;
  while (b != e) {
    int mid = (b + e) >> 1;
    if (tree[node << 1] >= nth) {
      node <<= 1;
      e = mid;
    } else {
      nth -= tree[node << 1];
      node = (node << 1) + 1;
      b = mid + 1;
    }
  }

  --tree[node];
  while (node >>= 1) --tree[node];

  return b + 1;
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
      int v = Query(b);
      cout << v << "\n";
    } else {
      cin >> c;
      Update(b - 1, c);
    }
  }

  return 0;
}
