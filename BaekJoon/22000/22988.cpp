// Title : 재활용 캠페인
// Link  : https://www.acmicpc.net/problem/22988 
// Time  : 24 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, x;
  cin >> n >> x;

  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  int64_t half = x >> 1;
  int cnt = 0, rem = 0, l = 0, r = n - 1;
  while (r >= 0 && arr[r] >= x) ++cnt, --r;
  while (l < r) {
    if (arr[l] + arr[r] + half >= x) {
      ++cnt;
      ++l, --r;
    } else {
      ++rem;
      ++l;
    }
  }
  cout << cnt + (rem + (l == r)) / 3;

  return 0;
}
