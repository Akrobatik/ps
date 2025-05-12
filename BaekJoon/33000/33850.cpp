// Title : Chill...은 내가 가장 좋아하는 소수
// Link  : https://www.acmicpc.net/problem/33850 
// Time  : 44 ms
// Memory: 4816 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 2e5;

bool seive[kMax + 1];

int memo[200001];

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

  int n, a, b;
  cin >> n >> a >> b;
  vector<int> arr(n), brr(n);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;

  auto GetValue = [&](int x) {
    if (seive[x]) return b;
    return a;
  };

  memo[1] = GetValue(arr[0] + brr[0]);
  for (int i = 2; i <= n; i++) {
    int x = GetValue(arr[i - 2] + arr[i - 1]) + GetValue(brr[i - 2] + brr[i - 1]);
    int y = GetValue(arr[i - 1] + brr[i - 1]);
    memo[i] = max<int>(memo[i - 2] + x, memo[i - 1] + y);
  }
  cout << memo[n];

  return 0;
}
