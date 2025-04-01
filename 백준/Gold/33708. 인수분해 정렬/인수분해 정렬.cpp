#include <bits/stdc++.h>

using namespace std;

bool memo[1000001];

int Calc(int x) {
  if (x == 1) return 0;
  return memo[x] + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> primes;
  for (int i = 2; i <= 1000000; i++) {
    if (!memo[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > 1000000) break;
      memo[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  bool b1 = true, b2 = false;
  for (int i = 1; !b2 && i < n; i++) {
    if (arr[i - 1] > arr[i]) b1 = false;
    b2 = (Calc(arr[i - 1]) + Calc(arr[i])) >= 2;
  }
  cout << ((b1 || b2) ? "YES" : "NO");

  return 0;
}
