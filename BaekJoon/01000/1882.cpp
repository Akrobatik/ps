// Title : 분수 찾기
// Link  : https://www.acmicpc.net/problem/1882 
// Time  : 112 ms
// Memory: 4320 KB

#include <bits/stdc++.h>

using namespace std;

constexpr double kEpsilon = 1e-9;

bool seive[40001];
vector<int> facts[40001];

int GCD(int a, int b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> primes;
  for (int i = 2; i <= n; i++) {
    if (!seive[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > n) break;
      seive[i * p] = true;
      if (i % p == 0) break;
    }
  }

  for (int i = 2; i <= n; i++) {
    int x = i;
    for (int j = 0; x > 1 && j < primes.size(); j++) {
      int p = primes[j];
      if (x % p) continue;
      facts[i].push_back(p);
      while (x % p == 0) x /= p;
    }
  }

  auto CountL = [&](int q, int c) {
    int res = c;
    auto& f = facts[q];
    for (int m = 1; m < (1 << f.size()); m++) {
      int prod = 1, bits = 0;
      for (int i = 0; i < f.size(); i++) {
        if (m & (1 << i)) {
          prod *= f[i];
          ++bits;
        }
      }

      if (prod > c) continue;

      int t = c / prod;
      if (bits & 1) {
        res -= t;
      } else {
        res += t;
      }
    }
    return res;
  };

  auto Count = [&](double x) {
    int res = 0;
    for (int q = 1; q <= n; q++) {
      int c = floor(x * (double)q);
      if (c == 0) continue;
      res += CountL(q, c);
    }
    return res;
  };

  double l = 0.0, r = 1.0;
  while (l + kEpsilon < r) {
    double mid = (l + r) / 2.0;
    if (Count(mid) < k) {
      l = mid;
    } else {
      r = mid;
    }
  }

  int ansp = 1, ansq = 1;
  double minn = DBL_MAX;
  for (int q = 1; q <= n; q++) {
    int p = floor(l * (double)q) + 1;
    if (p > q) continue;
    if (GCD(p, q) != 1) continue;

    double x = (double)p / (double)q;
    if (minn > x) minn = x, ansp = p, ansq = q;
  }

  cout << ansp << " " << ansq;

  return 0;
}
