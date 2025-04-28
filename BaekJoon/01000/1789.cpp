// Title : 수들의 합
// Link  : https://www.acmicpc.net/problem/1789 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t s;
  cin >> s;
  int64_t lo = 1, hi = INT_MAX;
  while (lo + 1 < hi) {
    int64_t mid = (lo + hi) >> 1;
    if (mid * (mid + 1) / 2 <= s) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << lo;

  return 0;
}
