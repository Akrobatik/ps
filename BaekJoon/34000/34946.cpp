// Title : 셔틀 탈래 말래 탈래 말래 애매하긴 해
// Link  : https://www.acmicpc.net/problem/34946 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  bool b1 = (a + b <= d);
  bool b2 = (c <= d);

  if (b1 && b2) {
    cout << "~.~";
  } else if (b1) {
    cout << "Shuttle";
  } else if (b2) {
    cout << "Walk";
  } else {
    cout << "T.T";
  }

  return 0;
}