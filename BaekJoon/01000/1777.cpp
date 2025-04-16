// Title : 순열복원
// Link  : https://www.acmicpc.net/problem/1777 
// Time  : 20 ms
// Memory: 3828 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 17;

int tree[kMax << 1];

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
  int res = node - kMax;
  while (node) --tree[node], node >>= 1;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  for (int i = 0; i < n; i++) {
    int node = i + kMax;
    while (node) ++tree[node], node >>= 1;
  }

  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int nth = n - i - arr[n - i - 1];
    ans[FindNth(nth)] = n - i;
  }

  for (auto e : ans) cout << e << " ";

  return 0;
}
