// Title : 짱해커 이동식
// Link  : https://www.acmicpc.net/problem/25603 
// Time  : 16 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  auto Check = [&](int x) {
    int prv = 0;
    for (int i = 1; i <= n; i++) {
      if (arr[i] > x) continue;
      if (i - prv > k) return false;
      prv = i;
    }
    return n - prv + 1 <= k;
  };

  int lo = 0, hi = 1e9;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (!Check(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << hi;

  return 0;
}
