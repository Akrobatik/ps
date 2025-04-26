// Title : LCM(1, 2, ..., n)
// Link  : https://www.acmicpc.net/problem/11690 
// Time  : 728 ms
// Memory: 122184 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e8;

bool seive[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> primes;
  primes.reserve(5761455);
  for (int i = 2; i <= kMax; i++) {
    if (!seive[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > kMax) break;
      seive[i * p] = true;
      if (i % p == 0) break;
    }
  }

  uint32_t n, ans = 1;
  cin >> n;
  for (auto p : primes) {
    if (p > n) break;
    int x = n, y = 1;
    while (x >= p) x /= p, y *= p;
    ans *= y;
  }
  cout << ans;

  return 0;
}
