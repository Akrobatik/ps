// Title : 수학은 비대면강의입니다
// Link  : https://www.acmicpc.net/problem/19532 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  for (int x = -999; x <= 999; x++) {
    for (int y = -999; y <= 999; y++) {
      if (a * x + b * y == c && d * x + e * y == f) {
        cout << x << " " << y;
        return 0;
      }
    }
  }

  return 0;
}
