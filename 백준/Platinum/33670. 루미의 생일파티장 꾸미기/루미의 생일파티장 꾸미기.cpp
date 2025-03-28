#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMax = 1e7;
constexpr int64_t kMod = 998244353;

bool seive[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, l;
  cin >> n >> l;

  vector<int64_t> primes;
  for (int64_t i = 2; i <= kMax; i++) {
    if (!seive[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > kMax) break;
      seive[i * p] = true;
      if (i % p == 0) break;
    }
  }

  vector<int64_t> memo(n + 1);
  iota(memo.begin(), memo.end(), 0);
  int np = primes.size();
  for (int i = 0; i < np; i++) {
    auto p = primes[i];
    for (int64_t j = p; j <= n; j += p) {
      memo[j] = memo[j] / p * (p - 1);
    }
  }

  int64_t phi = l;
  for (int64_t i = 0; i < np && l != 1; i++) {
    auto p = primes[i];
    if (l % p == 0) {
      while (l % p == 0) l /= p;
      phi -= phi / p;

      for (int64_t j = p; j <= n; j += p) {
        memo[j] += memo[j] / (p - 1);
      }
    }
  }
  if (l != 1) phi -= phi / l;

  int64_t sum = 0;
  for (int64_t i = 1; i <= n; i++) {
    sum += memo[i];
  }
  cout << (sum % kMod) * phi % kMod;

  return 0;
}