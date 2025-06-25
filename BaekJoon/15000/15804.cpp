// Title : 저거 못 타면 지각이야!!
// Link  : https://www.acmicpc.net/problem/15804 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> out(n);
  int cur = 0, maxx = 0, l = 0, r = 0;

  while (m--) {
    int t, p;
    cin >> t >> p;
    cur = max<int>(cur, t);
    while (l < r && out[l] <= cur) ++l;
    if (l == r) l = r = 0;
    if (r == n) cur = maxx, l = r = 0;
    out[r++] = cur + p;
    maxx = max<int>(maxx, cur + p);
    if (m == 0) cout << r;
  }

  return 0;
}
