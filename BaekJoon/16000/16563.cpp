// Title : 어려운 소인수분해
// Link  : https://www.acmicpc.net/problem/16563 
// Time  : 1584 ms
// Memory: 195028 KB

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 5e6;

string memo[kMax + 1];
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

  for (auto p : primes) {
    string s = to_string(p);
    for (int i = p; i <= kMax; i += p) {
      int x = i;
      do {
        memo[i].append(s).append(" ");
        x /= p;
      } while (x % p == 0);
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << memo[n] << "\n";
  }

  return 0;
}
