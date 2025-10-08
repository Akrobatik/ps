// Title : Catching the Krug
// Link  : https://www.acmicpc.net/problem/34627 
// Time  : 4 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

void Solve() {
  int n, ay, ax, by, bx;
  cin >> n >> ay >> ax >> by >> bx;
  if (ay > by) ay = n - ay, by = n - by;
  if (ax > bx) ax = n - ax, bx = n - bx;
  cout << max<int>(ay != by ? by : 0, ax != bx ? bx : 0) << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) Solve();

  return 0;
}
