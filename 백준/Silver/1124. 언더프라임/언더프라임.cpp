#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool memo[100001];
  memo[0] = memo[1] = true;
  for (int i = 2; i <= 100000; i++) {
    if (memo[i]) continue;
    for (int j = (i << 1); j <= 100000; j += i) memo[j] = true;
  }

  vector<int> primes;
  for (int i = 2; i <= 100000; i++) {
    if (memo[i]) continue;
    primes.push_back(i);
  }

  int a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = a; i <= b; i++) {
    int cnt = 0;
    int n = i;
    for (auto prime : primes) {
      if (n == 1) break;
      while ((n % prime) == 0) n /= prime, ++cnt;
    }
    if (!memo[cnt]) ++ans;
  }
  cout << ans;

  return 0;
}
