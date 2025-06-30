// Title : 우선순위 큐와 시뮬레이션
// Link  : https://www.acmicpc.net/problem/32718 
// Time  : 140 ms
// Memory: 4856 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 18;
int tree[kMax << 1];

int Query(int l, int r) {
  int res = -1;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max<int>(res, tree[l++]);
    if (r & 1) res = max<int>(res, tree[--r]);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(tree, -1, sizeof(tree));

  int n, k, t;
  cin >> n >> k >> t;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e, e %= k;
  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  n = arr.size();

  for (int i = 0; i < n; i++) {
    int x = arr[i];
    int node = i + kMax;
    while (node && tree[node] < x) tree[node] = x, node >>= 1;
  }

  int mid = 0;
  while (t--) {
    int x;
    cin >> x;
    mid = (mid + x) % k;

    int mi = upper_bound(arr.begin(), arr.end(), k - mid - 1) - arr.begin();
    int lv = Query(0, mi - 1), rv = Query(mi, n - 1);
    cout << (lv != -1 ? lv + mid : rv + mid - k) << " ";
  }

  return 0;
}
