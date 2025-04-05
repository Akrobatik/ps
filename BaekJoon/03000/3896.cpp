// Title : 소수 사이 수열
// Link  : https://www.acmicpc.net/problem/3896
// Time  : 8 ms
// Memory: 4184 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1299709;

int8_t cyrene[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> primes;
  for (int i = 2; i <= kMax; i++) {
    if (!cyrene[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > kMax) break;
      cyrene[i * p] = 1;
      if (i % p == 0) break;
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    auto b = lower_bound(primes.begin(), primes.end(), k);
    if (*b == k || b == primes.begin()) {
      cout << "0\n";
      continue;
    }
    auto e = b--;
    cout << *e - *b << "\n";
  }

  return 0;
}
