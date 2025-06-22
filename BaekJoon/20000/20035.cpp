// Title : 이동하기 5
// Link  : https://www.acmicpc.net/problem/20035 
// Time  : 12 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n), brr(m);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;

  int sa = 0, sb = 0;
  for (auto e : arr) sa += e;
  for (auto e : brr) sb += e;

  int ma = -1, l, r;
  for (int i = 0; i < n; i++) {
    if (ma < arr[i]) {
      ma = arr[i];
      l = r = i;
    } else if (ma == arr[i]) {
      r = i;
    }
  }

  int mb = -1;
  for (auto e : brr) mb = max<int>(mb, e);

  int64_t fwd = (int64_t)ma * (m - 1) + sa;
  int64_t bwd = (int64_t)mb * (r - l) + (int64_t)brr[0] * l + (int64_t)brr.back() * (n - r - 1) + sb;
  int64_t sum = fwd * (int)1e9 + bwd;
  cout << sum;

  return 0;
}
