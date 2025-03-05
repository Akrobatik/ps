#include <bits/stdc++.h>

using namespace std;

bool cyrene[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> primes;
  for (int i = 2; i <= 1000000; i++) {
    if (!cyrene[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > 1000000) break;
      cyrene[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int n;
  while (cin >> n && n) {
    bool found = false;
    for (auto p : primes) {
      if (p > n - p) break;
      if (!cyrene[n - p]) {
        found = true;
        cout << n << " = " << p << " + " << n - p << "\n";
        break;
      }
    }
    if (!found) cout << "Goldbach's conjecture is wrong.\n";
  }

  return 0;
}
