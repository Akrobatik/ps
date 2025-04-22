// Title : Professor KCM
// Link  : https://www.acmicpc.net/problem/13206 
// Time  : 120 ms
// Memory: 2052 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

constexpr array<int, 168> kPrimes = []() {
  array<int, 168> primes{};
  bool seive[1001] = {};
  int idx = 0;
  for (int i = 2; i <= 1000; i++) {
    if (!seive[i]) primes[idx++] = i;
    for (auto p : primes) {
      if (p == 0 || i * p > 1000) break;
      seive[i * p] = true;
      if (i % p == 0) break;
    }
  }
  return primes;
}();

constexpr array<array<pair<int, int>, 4>, 1001> kFacts = []() {
  array<array<pair<int, int>, 4>, 1001> facts{};
  for (int i = 2; i <= 1000; i++) {
    int x = i;
    auto it = facts[i].begin();
    for (auto p : kPrimes) {
      if (x % p == 0) {
        int cnt = 0;
        while (x % p == 0) x /= p, ++cnt;
        *it++ = {p, cnt};
        if (x == 1) break;
      }
    }
  }
  return facts;
}();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int memo[1001] = {};
    while (n--) {
      int x;
      cin >> x;
      for (auto [p, cnt] : kFacts[x]) {
        if (p == 0) break;
        memo[p] = max<int>(memo[p], cnt);
      }
    }

    int ans = 1;
    for (auto p : kPrimes) {
      if (memo[p] == 0) continue;
      int x = 1;
      while (memo[p]--) x *= p;
      ans = (int64_t)ans * x % kMod;
    }
    cout << ans << "\n";
  }

  return 0;
}
