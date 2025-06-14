// Title : 소수
// Link  : https://www.acmicpc.net/problem/2581 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n;
  cin >> m >> n;

  int sum = 0, minn = INT_MAX;

  bool seive[10001] = {};
  vector<int> primes;
  for (int i = 2; i <= n; i++) {
    if (!seive[i]) {
      primes.push_back(i);
      if (i >= m) {
        sum += i;
        minn = min<int>(minn, i);
      }
    }
    for (auto p : primes) {
      if (i * p > n) break;
      seive[i * p] = true;
      if (i % p == 0) break;
    }
  }

  if (sum == 0) {
    cout << "-1";
  } else {
    cout << sum << "\n"
         << minn;
  }

  return 0;
}
