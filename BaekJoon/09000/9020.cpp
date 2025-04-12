// Title : 골드바흐의 추측
// Link  : https://www.acmicpc.net/problem/9020 
// Time  : 8 ms
// Memory: 2244 KB

#include <bits/stdc++.h>

using namespace std;

bool memo[10001];
pair<int, int> ans[10001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> primes;
  for (int i = 2; i <= 10000; i++) {
    if (!memo[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > 10000) break;
      memo[i * p] = true;
      if (i % p == 0) break;
    }
  }

  for (int i = 4; i <= 10000; i += 2) {
    for (auto p : primes) {
      if (p > i - p) break;
      if (memo[i - p]) continue;
      ans[i] = {p, i - p};
    }
  }

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    auto [a, b] = ans[x];
    cout << a << " " << b << "\n";
  }

  return 0;
}
