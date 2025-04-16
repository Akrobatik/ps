// Title : 어깨동무
// Link  : https://www.acmicpc.net/problem/27932 
// Time  : 244 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  auto Check = [&](int x, int k) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (i != 0 && abs(arr[i - 1] - arr[i]) > x) {
        ++cnt;
      } else if (i + 1 != n && abs(arr[i] - arr[i + 1]) > x) {
        ++cnt;
      }
    }
    return cnt > k;
  };

  int lo = -1, hi = 1e9 + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (Check(mid, k)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << lo + 1;

  return 0;
}
