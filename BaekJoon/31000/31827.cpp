// Title : 소수 수열
// Link  : https://www.acmicpc.net/problem/31827 
// Time  : 4 ms
// Memory: 3508 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e6;

bool seive[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> primes;

  int n, k;
  cin >> n >> k;
  for (int i = 2; i <= kMax; i++) {
    if (!seive[i]) {
      primes.push_back(i);
      if (i % k == 1) {
        cout << i << " ";
        if (--n == 0) break;
      }
    }
    for (auto p : primes) {
      if (i * p > kMax) break;
      seive[i * p] = true;
      if (i % p == 0) break;
    }
  }

  return 0;
}