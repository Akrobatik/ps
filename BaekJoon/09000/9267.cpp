// Title : A+B
// Link  : https://www.acmicpc.net/problem/9267 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

tuple<int64_t, int64_t, int64_t> ExtGCD(int64_t a, int64_t b) {
  int64_t x = 1, y = 0;
  int64_t x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int64_t q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return {x, y, a1};
}

bool Check(__int128_t a, __int128_t b) {
  while (b) a %= b, swap(a, b);
  return a == 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b, s;
  cin >> a >> b >> s;

  if (a > b) swap(a, b);

  if (b == 0) {
    cout << (s == 0 ? "YES" : "NO");
    return 0;
  }

  if (a == 0) {
    cout << (s % b == 0 ? "YES" : "NO");
    return 0;
  }

  if (s == 0) {
    cout << "NO";
    return 0;
  }

  if (a == s || b == s) {
    cout << "YES";
    return 0;
  }

  auto [x, y, g] = ExtGCD(a, b);
  if (s % g) {
    cout << "NO";
    return 0;
  }
  if (x > y) swap(x, y), swap(a, b);
  a /= g, b /= g, s /= g;
  __int128_t xx = (__int128_t)x * s;
  __int128_t yy = (__int128_t)y * s;
  __int128_t m = (-xx + b) / b;
  xx += m * b, yy -= m * a;

  while (yy > 0) {
    if (Check(xx, yy)) {
      cout << "YES";
      return 0;
    }
    xx += b;
    yy -= a;
  }
  cout << "NO";

  return 0;
}
