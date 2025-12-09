// Title : 폭탄의 악마
// Link  : https://www.acmicpc.net/problem/34896 
// Time  : 48 ms
// Memory: 3224 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> arr(n);
  for (auto& [x, v] : arr) cin >> x;
  for (auto& [x, v] : arr) cin >> v;
  sort(arr.begin(), arr.end());

  int maxb;
  cin >> maxb;

  auto Check = [&](int limit) {
    int idx = 0, sumb = 0;
    while (idx < n) {
      int minn = arr[idx].second;
      while (idx + 1 < n && arr[idx + 1].first - arr[idx].first <= limit) minn = min<int>(minn, arr[++idx].second);
      sumb += minn, ++idx;
    }
    return sumb <= maxb;
  };

  int lo = 0, hi = 2e8;
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