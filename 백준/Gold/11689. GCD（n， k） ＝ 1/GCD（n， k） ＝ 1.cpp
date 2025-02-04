#include <bits/stdc++.h>

using namespace std;

bool memo[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  int nn = sqrt(n);
  int64_t ans = n;
  for (int i = 2; i <= nn; i++) {
    if (memo[i]) continue;
    for (int j = (i << 1); j <= nn; j += i) memo[j] = true;
    if (n % i != 0) continue;
    ans -= ans / i;
    while (n % i == 0) n /= i;
  }
  if (n != 1) ans -= ans / n;

  cout << ans;

  return 0;
}
