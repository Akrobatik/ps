// Title : 주사위 세개
// Link  : https://www.acmicpc.net/problem/2480 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;
  int d = (a == b) + (b == c) + (c == a);

  if (d == 3) {
    cout << 10000 + a * 1000;
  } else if (d == 1) {
    if (a == b || b == c) {
      cout << 1000 + 100 * b;
    } else {
      cout << 1000 + 100 * a;
    }
  } else {
    cout << max<int>({a, b, c}) * 100;
  }

  return 0;
}
