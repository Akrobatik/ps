// Title : Armageddon
// Link  : https://www.acmicpc.net/problem/34648 
// Time  : 12 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

int64_t Pow(int64_t a, int64_t exp) {
  int64_t res = 1;
  while (exp) {
    if (exp & 1) res = res * a % kMod;
    a = a * a % kMod;
    exp >>= 1;
  }
  return res;
}

int main() {
  int64_t p, q, n;
  cin >> p >> q >> n;

  int64_t limit = n;
  if (p > q) limit = min<int64_t>(limit, ((q << 1) / (p - q) + 1) << 1);

  int64_t x = 0, y = 0, xs = 0, ys = 0;
  for (int i = 1; i <= limit; i++) {
    if (i & 1) {
      xs += ++x;
    } else {
      ys += ++y;
    }
    cout << (xs * ys) % kMod << ' ';
  }

  int64_t zs = xs * ys % kMod, zm = p * Pow(q, kMod - 2) % kMod;
  for (int i = limit + 1; i <= n; i++) {
    zs = zs * zm % kMod;
    cout << zs << ' ';
  }

  return 0;
}