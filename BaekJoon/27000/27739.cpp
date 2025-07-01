// Title : 수열 재배열
// Link  : https://www.acmicpc.net/problem/27739 
// Time  : 0 ms
// Memory: 2172 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 11;
int tree[kMax << 1];

void Update(int idx, int delta) {
  int node = idx + kMax;
  while (node) tree[node] += delta, node >>= 1;
}

int Query(int l, int r) {
  int res = 0;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += tree[l++];
    if (r & 1) res += tree[--r];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> arr(n + 2), fwd(n + 2), bwd(n + 2), tmp(k);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  arr[n + 1] = INT_MAX;

  int l = 1, r = 1;
  while (l <= n) {
    r = max<int>(r, l);
    while (r + 1 <= n && arr[r] < arr[r + 1]) ++r;
    fwd[l++] = r - l + 1;
  }
  l = n, r = n;
  while (r >= 1) {
    l = min<int>(l, r);
    while (l - 1 >= 1 && arr[l - 1] < arr[l]) --l;
    bwd[r--] = r - l + 1;
  }

  for (int i = 1; i < k; i++) {
    Update(arr[i], 1);
  }

  int maxx = 0;
  for (int i = 1; i + k - 1 <= n; i++) {
    Update(arr[i + k - 1], 1);
    int mv = Query(arr[i - 1] + 1, arr[i + k] - 1);
    if (mv == k) {
      maxx = max<int>(maxx, bwd[i - 1] + fwd[i + k] + k);
    } else {
      int lv = Query(arr[i - 1] + 1, kMax - 1);
      int rv = Query(0, arr[i + k] - 1);
      maxx = max<int>({maxx, bwd[i - 1] + lv, fwd[i + k] + rv});
    }
    Update(arr[i], -1);
  }
  cout << maxx;

  return 0;
}
