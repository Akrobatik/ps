// Title : Prime Median
// Link  : https://www.acmicpc.net/problem/34558 
// Time  : 48 ms
// Memory: 3892 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e6;

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
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;

    auto lit = lower_bound(primes.begin(), primes.end(), a);
    auto rit = upper_bound(primes.begin(), primes.end(), b);

    int sz = rit - lit;
    if (sz & 1) {
      int half = sz >> 1;
      cout << lit[half] << "\n";
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}