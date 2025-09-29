// Title : Hostile Cooperation
// Link  : https://www.acmicpc.net/problem/34536 
// Time  : 112 ms
// Memory: 6716 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;

  vector<int64_t> arr(n), brr(n), crr(n);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;
  for (auto& e : crr) cin >> e;
  sort(arr.begin(), arr.end());
  sort(brr.begin(), brr.end());
  sort(crr.begin(), crr.end());

  if (n == 1) {
    cout << abs(arr[0] + brr[0] + crr[0] - k);
    return 0;
  }

  int64_t ans = INT64_MAX;
  int64_t c1 = crr.front(), c2 = crr.back();
  int64_t pv = k - ((c1 + c2 + 1) >> 1);
  int ai = 0, bi = n - 2;
  while (ai < n) {
    int64_t av = arr[ai++];
    while (bi > 0 && av + brr[bi] >= pv) --bi;
    int64_t b1 = brr[bi], b2 = brr[bi + 1];
    int64_t v1 = max<int64_t>(abs(av + b1 + c1 - k), abs(av + b1 + c2 - k));
    int64_t v2 = max<int64_t>(abs(av + b2 + c1 - k), abs(av + b2 + c2 - k));
    ans = min<int64_t>({ans, v1, v2});
  }
  cout << ans;

  return 0;
}