#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = (1 << 13) - 1;
int tree[(kMax + 1) << 1];

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
  while ((node >>= 1)) --tree[node];

  return b + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int node = i + kMax + 1;
    ++tree[node];
    while ((node >>= 1)) ++tree[node];
  }

  cout << "<";
  int nth = 1;
  for (int i = 1; i < n; i++) {
    nth += k - 1;
    while (nth > tree[1]) nth -= tree[1];
    cout << Query(nth) << ", ";
  }
  cout << Query(1) << ">";

  return 0;
}
