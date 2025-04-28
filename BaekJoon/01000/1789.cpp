// Title : 수들의 합
// Link  : https://www.acmicpc.net/problem/1789 
// Time  : 0 ms
// Memory: 2032 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t s;
  cin >> s;
  s <<= 1;
  int64_t x = sqrt((long double)s);
  if (x * (x + 1) > s) --x;
  cout << x;

  return 0;
}
