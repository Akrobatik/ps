#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 7368787;
bool cyrene[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> primes;
  for (int i = 2; i < kMax; i++) {
    if (!cyrene[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > kMax) break;
      cyrene[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int n;
  cin >> n;
  cout << primes[n - 1];

  return 0;
}
