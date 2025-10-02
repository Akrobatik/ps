// Title : 특수한 정수 쌍
// Link  : https://www.acmicpc.net/problem/34554 
// Time  : 0 ms
// Memory: 2168 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e4 + 1;

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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    if (seive[n + 1]) {
      cout << "0\n";
    } else {
      cout << "1\n"
           << "1 " << n + 1 << "\n";
    }
  }

  return 0;
}