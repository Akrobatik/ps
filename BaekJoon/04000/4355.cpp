// Title : 서로소
// Link  : https://www.acmicpc.net/problem/4355 
// Time  : 0 ms
// Memory: 2196 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 4e4;

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

  int np = primes.size();

  int64_t n;
  while (cin >> n && n) {
    if (n == 1) {
      cout << "0\n";
      continue;
    }

    int64_t phi = n;
    for (int i = 0; n != 1 && i < np; i++) {
      int p = primes[i];
      if (n % p) continue;
      while (n % p == 0) n /= p;
      phi -= phi / p;
    }
    if (n != 1) phi -= phi / n;
    cout << phi << "\n";
  }

  return 0;
}
