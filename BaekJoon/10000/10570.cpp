// Title : Favorite Number
// Link  : https://www.acmicpc.net/problem/10570 
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
    int n;
    cin >> n;
    int cnts[1001] = {};
    int maxx = 0, ans;
    while (n--) {
      int x;
      cin >> x;
      int cnt = ++cnts[x];
      if (cnt == maxx) {
        ans = min<int>(ans, x);
      } else if (cnt == maxx + 1) {
        ++maxx, ans = x;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
