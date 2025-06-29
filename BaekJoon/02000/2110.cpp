// Title : 공유기 설치
// Link  : https://www.acmicpc.net/problem/2110 
// Time  : 36 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, c;
  cin >> n >> c;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  auto Check = [&](int x) {
    int cnt = 1, prv = arr[0];
    for (int i = 1; i < n; i++) {
      if (arr[i] - prv < x) continue;
      ++cnt, prv = arr[i];
    }
    return cnt >= c;
  };

  int lo = 1, hi = 1e9 + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (Check(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << lo;

  return 0;
}