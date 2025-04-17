// Title : 거의 소수
// Link  : https://www.acmicpc.net/problem/1456 
// Time  : 80 ms
// Memory: 18072 KB

#include <bits/stdc++.h>

using namespace std;

bool seive[(int)(1e7 + 1)];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b;
  cin >> a >> b;

  vector<int> primes;
  int limit = sqrt(b);
  for (int i = 2; i <= limit; i++) {
    if (!seive[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > limit) break;
      seive[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int64_t sum = 0;
  for (auto p : primes) {
    int64_t x = p;
    while (x <= b / p) x *= p, sum += (x >= a);
  }
  cout << sum;

  return 0;
}
