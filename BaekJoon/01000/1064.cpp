// Title : 평행사변형
// Link  : https://www.acmicpc.net/problem/1064 
// Time  : 0 ms
// Memory: 2036 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int ay, ax, by, bx, cy, cx;
  cin >> ay >> ax >> by >> bx >> cy >> cx;

  long double a = sqrtl((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
  long double b = sqrtl((bx - cx) * (bx - cx) + (by - cy) * (by - cy));
  long double c = sqrtl((cx - ax) * (cx - ax) + (cy - ay) * (cy - ay));
  long double d = max<long double>({a, b, c});
  if (a + b + c - d <= d) {
    cout << "-1.0";
    return 0;
  }

  long double maxx = (a + b + c - min<long double>({a, b, c}));
  long double minn = (a + b + c - max<long double>({a, b, c}));

  cout << setprecision(12) << fixed << (maxx - minn) * 2.0;

  return 0;
}
