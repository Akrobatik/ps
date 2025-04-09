// Title : 비로소 서로소
// Link  : https://www.acmicpc.net/problem/32240 
// Time  : 2864 ms
// Memory: 795136 KB

#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 5e7;
constexpr int64_t kMod = 1e9 + 7;
constexpr int64_t kInv2 = 500000004;
constexpr int64_t kInv6 = 166666668;

int64_t phi[kMax + 1], psum[kMax + 1];
unordered_map<int64_t, int64_t> memo;

int64_t PrefixSum(int64_t n) {
  if (n <= kMax) return psum[n];
  if (auto it = memo.find(n); it != memo.end()) return it->second;

  int64_t nmod = n % kMod;
  // int64_t a = ((nmod + 1) * (nmod + 1) % kMod) * nmod * 3 % kMod;
  // int64_t b = (nmod * (nmod + 1) % kMod) * (nmod + 2) % kMod;
  // int64_t res = (a + kMod - b) * kInv6 % kMod;
  int64_t res = (nmod * 2 + 1) * (nmod + 1) % kMod * nmod % kMod * kInv6 % kMod;
  for (int64_t i = 2, j; i <= n; i = j + 1) {
    int64_t x = n / i;
    j = n / x;
    int64_t y = (j - i + 1) % kMod;
    int64_t z = (i + j) % kMod;
    res -= ((PrefixSum(x) * y % kMod) * z % kMod) * kInv2 % kMod;
    if (res < 0) res += kMod;
  }
  return memo[n] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> primes;
  primes.reserve(3001134);
  phi[1] = 1;
  for (int i = 2; i <= kMax; ++i) {
    if (phi[i] == 0) {
      phi[i] = i - 1;
      primes.push_back(i);
    }
    for (auto p : primes) {
      if (i * p > kMax) break;
      if (i % p == 0) {
        phi[i * p] = phi[i] * p;
        break;
      } else {
        phi[i * p] = phi[i] * (p - 1);
      }
    }
  }

  for (int i = 1; i <= kMax; i++) {
    psum[i] = (psum[i - 1] + phi[i] * i) % kMod;
  }

  int64_t n;
  cin >> n;
  cout << (PrefixSum(n) * 3 + kMod - 1) % kMod;

  return 0;
}
