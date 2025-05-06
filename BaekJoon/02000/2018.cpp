// Title : 수들의 합 5
// Link  : https://www.acmicpc.net/problem/2018 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int lo = 1, hi = 10000;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (mid * (mid + 1) / 2 <= n) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  int cnt = 0;
  for (int i = 1; i <= lo; i++) {
    if (i & 1) {
      if (n % i == 0) ++cnt;
    } else {
      int half = i >> 1;
      if (n % half == 0 && (n / half) % 2 == 1) ++cnt;
    }
  }
  cout << cnt;

  return 0;
}
