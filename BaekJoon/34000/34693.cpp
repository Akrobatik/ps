// Title : 마법소녀 코이
// Link  : https://www.acmicpc.net/problem/34693 
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

    int64_t y = (x + 1) >> 1;
    if (x & 1) {
      cout << y + 2 << " - " << y + 1 << " - 2\n";
    } else {
      int64_t y = x >> 1;
      cout << y + 1 << " - " << y << " - 1\n";
    }
  }

  return 0;
}