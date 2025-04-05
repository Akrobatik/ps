// Title : 지각
// Link  : https://www.acmicpc.net/problem/10419
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
    int64_t res = 0;
    while (res * res + res <= x) ++res;
    cout << res - 1 << "\n";
  }

  return 0;
}
