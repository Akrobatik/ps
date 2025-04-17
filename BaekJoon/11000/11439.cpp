// Title : 이항 계수 5
// Link  : https://www.acmicpc.net/problem/11439 
// Time  : 76 ms
// Memory: 19000 KB

#include <bits/stdc++.h>

using namespace std;

bool seive[4000001];

vector<int64_t> Count(int64_t n, const vector<int64_t>& primes) {
  vector<int64_t> res;
  res.reserve(primes.size());
  for (auto p : primes) {
    int64_t x = n, cnt = 0;
    while (x) x /= p, cnt += x;
    res.push_back(cnt);
  }
  return res;
}

vector<int64_t> Factorize(int64_t n, const vector<int64_t>& primes) {
  vector<int64_t> res;
  res.reserve(primes.size());
  for (auto p : primes) {
    int64_t cnt = 0;
    while (n % p == 0) n /= p, ++cnt;
    res.push_back(cnt);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, m;
  cin >> n >> k >> m;

  vector<int64_t> primes;
  int64_t limit = max<int64_t>(n, m);
  for (int64_t i = 2; i <= limit; i++) {
    if (!seive[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > limit) break;
      seive[i * p] = true;
      if (i % p == 0) break;
    }
  }

  auto nc = Count(n, primes);
  auto kc = Count(k, primes);
  auto nkc = Count(n - k, primes);
  auto mc = Factorize(m, primes);

  for (int i = 0; i < primes.size(); i++) {
    nc[i] -= kc[i] + nkc[i];
  }

  int64_t mp = 1;
  for (int64_t i = 0; i < primes.size(); i++) {
    if (mc[i] == 0) continue;
    int64_t cut = min<int64_t>(nc[i], mc[i]);
    nc[i] -= cut, mc[i] -= cut;
    for (int64_t j = 0; j < mc[i]; j++) {
      mp *= primes[i];
    }
  }

  if (mp == 1) {
    cout << "0";
    return 0;
  }

  int64_t res = 1;
  for (int64_t i = 0; i < primes.size(); i++) {
    if (nc[i] == 0) continue;
    for (int64_t j = 0; j < nc[i]; j++) {
      res = res * primes[i] % mp;
    }
  }
  cout << res * (m / mp);

  return 0;
}
