// Title : XOr
// Link  : https://www.acmicpc.net/problem/31355 
// Time  : 48 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    arr[i] = arr[i - 1] ^ x;
  }

  auto Check = [&](int x) {
    int mask = ~x;
    int cnt = 0, l = 0;
    while (cnt + 1 < m && l < n) {
      int r = l + 1;
      while (r <= n && ((arr[l] ^ arr[r]) & mask)) ++r;
      cnt += (r <= n);
      l = r;
    }
    return (cnt + 1 == m && l < n && ((arr[l] ^ arr[n]) & mask) == 0);
  };

  int lo = -1, hi = INT_MAX;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (Check(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << hi;

  return 0;
}
