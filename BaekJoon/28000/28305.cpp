// Title : 세미나 배정
// Link  : https://www.acmicpc.net/problem/28305 
// Time  : 40 ms
// Memory: 3592 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t;
  cin >> n >> t;
  vector<int> arr(n), memo(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  auto Check = [&](int x) {
    for (int i = 0; i < x; i++) {
      memo[i] = max<int>(arr[i] - t + 1, 1);
    }
    for (int i = x; i < n; i++) {
      memo[i] = max<int>(arr[i] - t + 1, memo[i - x] + t);
      if (arr[i] < memo[i]) return false;
    }
    return true;
  };

  int lo = 0, hi = n;
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
