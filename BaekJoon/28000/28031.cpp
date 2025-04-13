// Title : Milk Sum
// Link  : https://www.acmicpc.net/problem/28031 
// Time  : 124 ms
// Memory: 5540 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;

  auto brr = arr;
  sort(brr.begin(), brr.end());

  int64_t sum = 0;
  for (int i = 0; i < n; i++) {
    sum += brr[i] * (i + 1);
  }

  vector<int64_t> crr(n + 1);
  partial_sum(brr.begin(), brr.end(), crr.begin() + 1);

  int q;
  cin >> q;
  while (q--) {
    int64_t a, b;
    cin >> a >> b;
    a = arr[a - 1];

    if (a == b) {
      cout << sum << "\n";
    } else if (a < b) {
      int aidx = upper_bound(brr.begin(), brr.end(), a) - brr.begin();
      int bidx = upper_bound(brr.begin(), brr.end(), b) - brr.begin();
      int64_t ans = sum - a * aidx + b * bidx - (crr[bidx] - crr[aidx]);
      cout << ans << "\n";
    } else {
      int aidx = upper_bound(brr.begin(), brr.end(), a) - brr.begin();
      int bidx = upper_bound(brr.begin(), brr.end(), b) - brr.begin();
      int64_t ans = sum - a * aidx + b * (bidx + 1) + (crr[aidx - 1] - crr[bidx]);
      cout << ans << "\n";
    }
  }

  return 0;
}
