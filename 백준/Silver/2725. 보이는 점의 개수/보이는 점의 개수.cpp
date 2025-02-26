#include <bits/stdc++.h>

using namespace std;

constexpr array<int, 168> kPrimes = []() {
  array<int, 168> arr{};
  auto ptr = arr.data();
  bool memo[1001] = {};
  for (int i = 2; i <= 1000; i++) {
    if (memo[i]) continue;
    *ptr++ = i;
    for (int j = i << 1; j <= 1000; j += i) memo[j] = true;
  }
  return arr;
}();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int memo[1001] = {};
  memo[1] = 3;
  for (int i = 2; i <= 1000; i++) {
    int n = i, sum = i;
    for (int j = 0; n != 1; j++) {
      if (n % kPrimes[j] == 0) {
        sum -= sum / kPrimes[j];
        do {
           n /= kPrimes[j];
        } while(n % kPrimes[j] == 0);
      }
    }
    memo[i] = memo[i - 1] + (sum << 1);
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
