// Title : 기타 레슨
// Link  : https://www.acmicpc.net/problem/2343 
// Time  : 12 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  auto Check = [&](int64_t x) {
    int cnt = 0, idx = 0;
    while (idx < n) {
      int64_t sum = 0;
      while (idx < n && sum + arr[idx] <= x) sum += arr[idx++];
      ++cnt;
    }
    return cnt <= m;
  };

  int64_t lo = *max_element(arr.begin(), arr.end()) - 1, hi = 2e9;
  while (lo + 1 < hi) {
    int64_t mid = (lo + hi) >> 1;
    if (Check(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << hi;

  return 0;
}