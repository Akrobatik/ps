// Title : 1교시： 가정
// Link  : https://www.acmicpc.net/problem/33631
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int f, c, e, b, rf, rc, re, rb, q;
  cin >> f >> c >> e >> b >> rf >> rc >> re >> rb >> q;
  int cnt = 0;
  while (q--) {
    int cmd, i;
    cin >> cmd >> i;
    switch (cmd) {
      case 1: {
        if (rf * i <= f && rc * i <= c && re * i <= e && rb * i <= b) {
          f -= rf * i;
          c -= rc * i;
          e -= re * i;
          b -= rb * i;
          cnt += i;
          cout << cnt << "\n";
        } else {
          cout << "Hello, siumii\n";
        }
      } break;
      case 2: {
        f += i;
        cout << f << "\n";
      } break;
      case 3: {
        c += i;
        cout << c << "\n";
      } break;
      case 4: {
        e += i;
        cout << e << "\n";
      } break;
      case 5: {
        b += i;
        cout << b << "\n";
      } break;
    }
  }

  return 0;
}
