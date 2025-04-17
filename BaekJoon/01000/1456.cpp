// Title : 거의 소수
// Link  : https://www.acmicpc.net/problem/1456 
// Time  : 124 ms
// Memory: 18060 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e7;

bool seive[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b;
  cin >> a >> b;

  vector<int> primes;
  for (int64_t i = 2; i * i <= b; i++) {
    if (!seive[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > kMax) break;
      seive[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int64_t sum = 0;
  for (auto p : primes) {
    __int128_t x = (__int128_t)p * p;
    while (x <= b) sum += (x >= a), x *= p;
  }
  cout << sum;

  return 0;
}
