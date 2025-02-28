#include <bits/stdc++.h>

using namespace std;

bool memo[1000001];
int primes[1000000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto pend = primes;
  for (int64_t i = 2; i <= 1000000; i++) {
    if (memo[i]) continue;
    *pend++ = i;
    for (int64_t j = i * i; j <= 1000000ll; j += i) {
      memo[j] = true;
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0;
    auto b = primes, e = pend;
    while (b < e) {
      int sum = b[0] + e[-1];
      if (sum == n) {
        ++ans;
        ++b;
      } else if (sum > n) {
        e = upper_bound(b, e, n - b[0]);
      } else {
        b = lower_bound(b, e, n - e[-1]);
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
