// Title : 걸어가요
// Link  : https://www.acmicpc.net/problem/34036 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

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

int64_t Inv(int64_t a, int64_t m) {
  int64_t x, y;
  int64_t g = ExtGCD(a, m, x, y);
  if ((x %= m) < 0) x += m;
  return x;
}

int64_t GetNext(int64_t ax, int64_t as, int64_t bx, int64_t bs, int64_t g) {
  int64_t d = (bx - ax) / g;
  int64_t s = bs / g;
  int64_t inv = Inv(as / g, s);
  int64_t t = (d % s * inv) % s;
  if (t < 0) t += s;
  return ax + as * t;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> xrr(n), srr(n);
  for (int i = 0; i < n; i++) {
    cin >> xrr[i] >> srr[i];
  }

  int64_t x = xrr[0], s = srr[0];
  for (int i = 1; i < n; i++) {
    int64_t g = GCD(s, srr[i]);
    if (abs(x - xrr[i]) % g) {
      cout << "-1";
      return 0;
    }
    int64_t ns = s * (srr[i] / g);
    int64_t nx = GetNext(x, s, xrr[i], srr[i], g);
    int64_t mx = max<int64_t>(x, xrr[i]);
    if (nx < mx) nx += ((mx - nx) / ns) * ns;
    if (nx < mx) nx += ns;
    x = nx, s = ns;
  }
  cout << x;

  return 0;
}
