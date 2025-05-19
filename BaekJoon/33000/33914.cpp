// Title : A = B ⊕ C
// Link  : https://www.acmicpc.net/problem/33914 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 2000;
constexpr int kMod = 1e9 + 7;

int64_t Power(int64_t x, int64_t exp) {
  int64_t res = 1;
  while (exp) {
    if (exp & 1) res = res * x % kMod;
    x = x * x % kMod;
    exp >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t fact[kMax + 1], inv[kMax + 1];
  fact[0] = 1;
  for (int i = 1; i <= kMax; i++) fact[i] = (fact[i - 1] * i) % kMod;
  inv[kMax] = Power(fact[kMax], kMod - 2);
  for (int i = kMax; i > 0; i--) inv[i - 1] = (inv[i] * i) % kMod;

  auto Comb = [&](int n, int r) -> int64_t {
    return (((fact[n] * inv[r]) % kMod) * inv[n - r]) % kMod;
  };

  int x, y;
  cin >> x >> y;

  if (x & 1) {
    cout << "0";
    return 0;
  }

  int half = x >> 1;
  if ((y - half) % 3 || y < half) {
    cout << "0";
    return 0;
  }

  int t1 = half, t2 = (y - half) / 3;
  cout << (Comb(t1 + t2, t1) * Power(3, t1) % kMod);

  return 0;
}