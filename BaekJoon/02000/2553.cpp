// Title : 마지막 팩토리얼 수
// Link  : https://www.acmicpc.net/problem/2553
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int64_t res = 1;
  for (int i = 2; i <= n; i++) {
    res *= i;
    while (res % 10 == 0) res /= 10;
    res %= 1000000;
  }
  cout << res % 10;

  return 0;
}
