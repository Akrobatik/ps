// Title : 아이스크림 접기
// Link  : https://www.acmicpc.net/problem/34852 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;

  long double x = n;
  cout << setprecision(6) << fixed << x * x * (9.0L - 5.0L * sqrt(3.0L)) / 3.0L;

  return 0;
}