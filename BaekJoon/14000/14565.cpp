// Title : 역원(Inverse) 구하기
// Link  : https://www.acmicpc.net/problem/14565 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int64_t ExtGCD(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }

  int64_t x1, y1;
  int64_t g = ExtGCD(b, a % b, x1, y1);
  x = y1, y = x1 - (a / b) * y1;
  return g;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, a;
  cin >> n >> a;

  int64_t x, y;
  int64_t g = ExtGCD(a, n, x, y);
  cout << (a ? n - a : 0) << " " << (g == 1 ? (x % n + n) % n : -1);

  return 0;
}