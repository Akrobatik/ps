// Title : Soma de quantidade prima de primos consecutivos
// Link  : https://www.acmicpc.net/problem/30666 
// Time  : 12 ms
// Memory: 5224 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e6;

bool seive[kMax + 1];
bool memo[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> primes;
  for (int i = 2; i <= kMax; i++) {
    if (!seive[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > kMax) break;
      seive[i * p] = true;
      if (i % p == 0) break;
    }
  }
  int np = primes.size();

  vector<int64_t> fwd(np + 1);
  for (int i = 0; i < np; i++) {
    fwd[i + 1] = fwd[i] + primes[i];
  }

  for (auto p : primes) {
    for (int i = 0; i + p <= np; i++) {
      int64_t x = fwd[i + p] - fwd[i];
      if (x > kMax) break;
      memo[x] = true;
    }
  }

  int n;
  while (cin >> n && n != 0) {
    cout << (memo[n] ? "SIM\n" : "NAO\n");
  }

  return 0;
}