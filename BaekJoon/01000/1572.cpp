// Title : 중앙값
// Link  : https://www.acmicpc.net/problem/1572 
// Time  : 48 ms
// Memory: 4024 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 17;

int tree[kMax << 1];

void Inc(int n) {
  int node = n + kMax;
  while (node) ++tree[node], node >>= 1;
}

void Dec(int n) {
  int node = n + kMax;
  while (node) --tree[node], node >>= 1;
}

int FindNth(int nth) {
  int node = 1;
  while (node < kMax) {
    if (nth <= tree[node << 1]) {
      node <<= 1;
    } else {
      nth -= tree[node << 1];
      node = (node << 1) + 1;
    }
  }
  return node - kMax;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int64_t sum = 0;
  int nth = (k + 1) >> 1;
  for (int i = 1; i <= n; i++) {
    Inc(arr[i - 1]);
    if (i >= k) {
      sum += FindNth(nth);
      Dec(arr[i - k]);
    }
  }
  cout << sum;

  return 0;
}
