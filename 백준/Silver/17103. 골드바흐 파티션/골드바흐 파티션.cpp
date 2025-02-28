#include <bits/stdc++.h>

using namespace std;

bool memo[1000001];
int primes[1000000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto pend = primes;
  memo[0] = memo[1] = true;
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
    int ans = 0, mid = n >> 1;
    for (auto it = primes; it != pend && *it <= mid; ++it) {
      ans += !memo[n - *it];
    }
    cout << ans << "\n";
  }

  return 0;
}
