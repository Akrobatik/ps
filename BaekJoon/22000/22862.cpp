// Title : 가장 긴 짝수 연속한 부분 수열 (large)
// Link  : https://www.acmicpc.net/problem/22862 
// Time  : 96 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e, e &= 1;

  int maxx = 0, l = 0, r = 0, sum[2] = {};
  while (l < n) {
    while (r < n && sum[1] + arr[r] <= k) ++sum[arr[r++]];
    maxx = max<int>(maxx, sum[0]);
    --sum[arr[l++]];
  }
  cout << maxx;

  return 0;
}
