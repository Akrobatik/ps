// Title : 분수찾기
// Link  : https://www.acmicpc.net/problem/1193 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int lo = 0, hi = 4500;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (mid * (mid + 1) / 2 < n) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  int st = lo * hi / 2 + 1;
  int sum = hi + 1;
  int y = n - st + 1, x = sum - y;
  if (sum & 1) swap(x, y);
  cout << x << "/" << y;

  return 0;
}
