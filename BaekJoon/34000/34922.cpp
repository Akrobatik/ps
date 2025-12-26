// Title : 사각지대
// Link  : https://www.acmicpc.net/problem/34922 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int w, h, r;
  cin >> w >> h >> r;

  long double v = (long double)(w * h) - acos(-1.0L) * 0.25L * (long double)(r * r);
  cout << setprecision(2) << fixed << v;

  return 0;
}