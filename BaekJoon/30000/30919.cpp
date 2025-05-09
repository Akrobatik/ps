// Title : 짧은 코드로 빠르게 많은 소수 세기
// Link  : https://www.acmicpc.net/problem/30919 
// Time  : 412 ms
// Memory: 156832 KB


#include <bits/stdc++.h>

using namespace std;

constexpr int kSMax = 1e6;
constexpr int kCMax = 1e4;
constexpr int kMax = 1e7 + 1;
constexpr int kMaxN = 50;
constexpr int kMaxM = 2 * 3 * 7 * 5 * 11 * 13 * 17;
constexpr int kMul[] = {2, 6, 30, 210, 2310, 30030, 510510};
constexpr int kMaxP = sizeof(kMul) / sizeof(int);

bool seive[kMax];
int cnt[kMax], memo[kMaxN][kMaxM];
vector<int> primes;

int Sqrt(int64_t x) {
  int lo = 0, hi = kSMax + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if ((int64_t)mid * mid <= x) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return lo;
}

int Cbrt(int64_t x) {
  int lo = 0, hi = kCMax + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if ((int64_t)mid * mid * mid <= x) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return lo;
}

int64_t Phi(int n, int64_t m) {
  if (n == 0) return m;
  if (n < kMaxN && m < kMaxM) return memo[n][m];
  if (n < kMaxP) return memo[n][m % kMul[n - 1]] + (m / kMul[n - 1]) * memo[n][kMul[n - 1]];

  int64_t p = primes[n - 1];
  if (m < kMax && p * p >= m) return cnt[m] - n + 1;
  if (m >= kMax || p * p * p < m) return Phi(n - 1, m) - Phi(n - 1, m / p);

  int limit = cnt[Sqrt(m)];
  int64_t res = cnt[m] - (limit + n - 2) * (limit - n + 1) / 2;
  for (int i = n; i < limit; i++) {
    res += cnt[m / primes[i]];
  }
  return res;
}

int64_t Calc(int64_t x) {
  if (x < kMax) return cnt[x];

  int s = Sqrt(x), c = Cbrt(x);
  int64_t res = Phi(cnt[c], x) + cnt[c] - 1;
  int limit = cnt[s];
  for (int i = cnt[c]; i < limit; i++) {
    res -= Calc(x / primes[i]) - i;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 2; i < kMax; i++) {
    cnt[i] = cnt[i - 1];
    if (!seive[i]) ++cnt[i], primes.push_back(i);
    for (auto p : primes) {
      if (i * p >= kMax) break;
      seive[i * p] = true;
      if (i % p == 0) break;
    }
  }

  for (int i = 0; i < kMaxM; i++) memo[0][i] = i;
  for (int i = 1; i < kMaxN; i++) {
    for (int j = 1; j < kMaxM; j++) {
      memo[i][j] = memo[i - 1][j] - memo[i - 1][j / primes[i - 1]];
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int64_t x;
    cin >> x;
    cout << Calc(x) << "\n";
  }

  return 0;
}