// Title : Balloons
// Link  : https://www.acmicpc.net/problem/8363 
// Time  : 76 ms
// Memory: 6720 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  vector<int> brr(m);
  for (auto& e : brr) cin >> e;
  sort(brr.begin(), brr.end(), greater<int>());

  vector<int64_t> axr(n + 1), bxr(m + 1);
  for (int i = 0; i < n; i++) axr[i + 1] = axr[i] + arr[i];
  for (int i = 0; i < m; i++) bxr[i + 1] = bxr[i] + brr[i];

  bool ok = true;
  for (int i = 1; i <= m; i++) {
    int x = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
    int64_t y = axr[x] + (int64_t)(n - x) * i;
    if (y < bxr[i]) {
      ok = false;
      break;
    }
  }
  cout << (ok ? "TAK" : "NIE");

  return 0;
}