// Title : Balloons
// Link  : https://www.acmicpc.net/problem/8363 
// Time  : 64 ms
// Memory: 5152 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int64_t> arr(n + 1), brr(m + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= m; i++) cin >> brr[i];
  sort(arr.begin() + 1, arr.end());
  sort(brr.begin() + 1, brr.end(), greater<int>());

  for (int i = 0; i < n; i++) arr[i + 1] += arr[i];
  for (int i = 0; i < m; i++) brr[i + 1] += brr[i];

  bool ok = true;
  int idx = 0;
  for (int i = 1; ok && i <= m; i++) {
    while (idx < n && arr[idx + 1] - arr[idx] < i) ++idx;
    ok = (arr[idx] + (int64_t)(n - idx) * i >= brr[i]);
  }
  cout << (ok ? "TAK" : "NIE");

  return 0;
}