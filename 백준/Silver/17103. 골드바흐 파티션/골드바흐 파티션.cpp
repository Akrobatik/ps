#include <bits/stdc++.h>

using namespace std;

bool memo[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> primes;
  for (int i = 2; i <= 1000000; i++) {
    if (!memo[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > 1000000) break;
      memo[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0;
    for (auto p : primes) {
      if (p > (n >> 1)) break;
      ans += binary_search(primes.begin(), primes.end(), n - p);
    }
    cout << ans << "\n";
  }

  return 0;
}
