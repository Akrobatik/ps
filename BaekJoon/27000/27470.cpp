// Title : 멋진 부분집합
// Link  : https://www.acmicpc.net/problem/27470 
// Time  : 332 ms
// Memory: 8524 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e6;

int memo[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> primes;
  for (int i = 2; i <= kMax; i++) {
    if (!memo[i]) {
      memo[i] = i;
      primes.push_back(i);
    }
    for (auto p : primes) {
      if (i * p > kMax) break;
      memo[i * p] = p;
      if (i % p == 0) break;
    }
  }

  auto Find = [&](int x) {
    if (x <= kMax) return memo[x];
    for (auto p : primes) {
      if (x % p == 0) return p;
      if (p * p > (int)1e9) break;
    }
    return x;
  };

  auto Fact = [&](int x, vector<int>& out) {
    out.clear();
    while (x > 1) {
      int p = Find(x);
      out.push_back(p);
      while (x % p == 0) x /= p;
    }
  };

  int n;
  cin >> n;

  int half = (n + 1) >> 1;

  vector<int> arr(n), fact;
  for (auto& e : arr) cin >> e;

  auto Check = [&](int x) {
    int cnt = 0;
    for (auto e : arr) {
      if (e % x == 0) ++cnt;
    }
    return cnt >= half;
  };

  mt19937 gen(random_device{}());
  int t = 50, dv = 0;
  while (!dv && t--) {
    int id = gen() % n;
    Fact(arr[id], fact);

    for (auto p : fact) {
      if (Check(p)) {
        dv = p;
        break;
      }
    }
  }

  if (dv) {
    cout << "YES\n";
    for (auto e : arr) {
      if (e % dv) continue;
      cout << e << " ";
      if (--half == 0) break;
    }
  } else {
    cout << "NO";
  }

  return 0;
}