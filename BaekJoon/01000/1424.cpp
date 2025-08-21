// Title : 새 앨범
// Link  : https://www.acmicpc.net/problem/1424 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l, c;
  cin >> n >> l >> c;

  auto Check = [&](int x) {
    return (l + 1) * x - 1 <= c;
  };

  int lo = 1, hi = n + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (Check(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  int r = lo % 13;
  if (r == 0 || (r == 1 && n % lo != 0)) --lo;
  cout << (n + lo - 1) / lo;

  return 0;
}