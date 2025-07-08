// Title : 베르트랑 공준
// Link  : https://www.acmicpc.net/problem/4948 
// Time  : 0 ms
// Memory: 2528 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 123456 << 1;

bool seive[kMax + 1];

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

  int n;
  while (cin >> n && n) {
    auto lit = upper_bound(primes.begin(), primes.end(), n);
    auto rit = lower_bound(primes.rbegin(), primes.rend(), n << 1, greater<int>());
    cout << rit.base() - lit << "\n";
  }

  return 0;
}
