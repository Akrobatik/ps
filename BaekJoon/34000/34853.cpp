// Title : 세 배열 오름차순
// Link  : https://www.acmicpc.net/problem/34853 
// Time  : 596 ms
// Memory: 7596 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<vector<int>> arrs(n);
  for (auto& arr : arrs) {
    int x;
    cin >> x;
    arr.resize(x);
    for (auto& e : arr) cin >> e;
    sort(arr.begin(), arr.end());
  }

  while (q--) {
    int a, b, c, i;
    cin >> a >> b >> c >> i;

    auto& arr = arrs[a - 1];
    auto& brr = arrs[b - 1];
    auto& crr = arrs[c - 1];

    auto Check = [&](int x) {
      auto ap = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
      auto bp = upper_bound(brr.begin(), brr.end(), x) - brr.begin();
      auto cp = upper_bound(crr.begin(), crr.end(), x) - crr.begin();
      return ap + bp + cp < i;
    };

    int lo = -1, hi = kInf;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      if (Check(mid)) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    cout << hi << "\n";
  }

  return 0;
}