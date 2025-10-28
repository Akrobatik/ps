// Title : 반올림
// Link  : https://www.acmicpc.net/problem/4539 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t x;
    cin >> x;
    for (int64_t d = 10;; d *= 10) {
      if (x < d) break;
      int64_t r = x % d;
      x = x - r + ((r << 1) >= d ? d : 0);
    }
    cout << x << "\n";
  }

  return 0;
}