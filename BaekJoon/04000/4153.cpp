// Title : 직각삼각형
// Link  : https://www.acmicpc.net/problem/4153
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (;;) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0) break;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    cout << (c * c == a * a + b * b ? "right\n" : "wrong\n");
  }

  return 0;
}
