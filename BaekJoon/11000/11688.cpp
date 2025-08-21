// Title : 최소공배수 찾기
// Link  : https://www.acmicpc.net/problem/11688 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b, l;
  cin >> a >> b >> l;

  int64_t g = GCD(a, b);
  int64_t x = a * b / g;
  if (l % x) {
    cout << "-1";
    return 0;
  }

  int64_t y = l / x;
  int64_t res = 1;
  for (int i = 2; y > 1; i++) {
    if (y % i) continue;
    while (y % i == 0) y /= i, res *= i;

    int c1 = 0, c2 = 0;
    while (a % i == 0) a /= i, ++c1;
    while (b % i == 0) b /= i, ++c2;
    int cnt = max<int>(c1, c2);
    while (cnt--) res *= i;
  }
  cout << res;

  return 0;
}