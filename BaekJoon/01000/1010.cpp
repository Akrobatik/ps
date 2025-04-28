// Title : 다리 놓기
// Link  : https://www.acmicpc.net/problem/1010 
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
    int l, r;
    cin >> l >> r;
    if (l > r - l) l = r - l;
    int64_t x = 1;
    for (int i = 0; i < l; i++) {
      x = x * (r - i) / (i + 1);
    }
    cout << x << "\n";
  }

  return 0;
}
