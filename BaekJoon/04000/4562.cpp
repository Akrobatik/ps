// Title : No Brainer
// Link  : https://www.acmicpc.net/problem/4562 
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
    int64_t x, y;
    cin >> x >> y;
    cout << (x >= y ? "MMM BRAINS\n" : "NO BRAINS\n");
  }

  return 0;
}