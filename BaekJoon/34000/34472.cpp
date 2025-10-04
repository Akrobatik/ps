// Title : 교도소
// Link  : https://www.acmicpc.net/problem/34472 
// Time  : 64 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;

  int64_t m = accumulate(arr.begin(), arr.end(), 0LL) / n;
  for (auto& e : arr) e -= m;

  int64_t cnt = 0;
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < n; i++) {
      if (arr[i] <= 0) continue;
      cnt += arr[i];

      int nxt = i + 1;
      if (nxt == n) nxt = 0;

      arr[nxt] += arr[i];
      arr[i] = 0;
    }
  }
  cout << cnt;

  return 0;
}