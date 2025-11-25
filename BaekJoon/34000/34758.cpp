// Title : KUPC에 어서 오세요
// Link  : https://www.acmicpc.net/problem/34758 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y, t;
  cin >> x >> y >> t;
  while (t--) {
    int xx, yy;
    cin >> xx >> yy;
    cout << max<int>((x != xx) + (y != yy) - 1, 0) << "\n";
  }

  return 0;
}