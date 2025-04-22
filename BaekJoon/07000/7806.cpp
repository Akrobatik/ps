// Title : GCD!
// Link  : https://www.acmicpc.net/problem/7806 
// Time  : 0 ms
// Memory: 2192 KB

#include <bits/stdc++.h>

using namespace std;

bool seive[35001];
vector<int> primes;

vector<pair<int, int>> Factorize(int x) {
  vector<pair<int, int>> res;
  for (auto p : primes) {
    if (x % p) continue;
    int cnt = 0;
    while (x % p == 0) x /= p, ++cnt;
    res.push_back({p, cnt});
    if (x == 1) break;  
  }
  if (x != 1) res.push_back({x, 1});
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 2; i <= 35000; i++) {
    if (!seive[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > 35000) break;
      seive[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int n, k;
  while (cin >> n >> k) {
    int ans = 1;
    auto facts = Factorize(k);
    for (auto [p, cnt] : facts) {
      int x = n, y = 0, z = 1;
      while (x) x /= p, y += x;

      cnt = min<int>(cnt, y);
      while (cnt--) z *= p;
      ans *= z;
    }
    cout << ans << "\n";
  }

  return 0;
}
