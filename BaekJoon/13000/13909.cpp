// Title : 창문 닫기
// Link  : https://www.acmicpc.net/problem/13909 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int lo = 1, hi = 45826;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (mid * mid <= n) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << lo;

  return 0;
}