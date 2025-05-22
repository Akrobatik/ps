// Title : 반올림
// Link  : https://www.acmicpc.net/problem/2033 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int x = 1;
  for (;;) {
    if (n < x * 10) break;
    n = (n / (x * 10) + ((n % (x * 10)) / x >= 5)) * (x * 10);
    x *= 10;
  }
  cout << n;

  return 0;
}
