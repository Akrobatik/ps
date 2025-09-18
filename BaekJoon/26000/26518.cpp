// Title : 수열의 극한값
// Link  : https://www.acmicpc.net/problem/26518 
// Time  : 0 ms
// Memory: 2032 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t b, c;
  cin >> b >> c;

  cout << setprecision(6) << fixed
       << ((long double)b + sqrt((long double)(b * b + c * 4))) / 2.0L;

  return 0;
}