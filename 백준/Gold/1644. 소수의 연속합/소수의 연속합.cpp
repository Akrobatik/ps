#include <bits/stdc++.h>

using namespace std;

bool memo[4000000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int limit = (int)sqrt((float)n);
  for (int i = 2; i <= limit; i++) {
    int v = i;
    while ((v += i) <= n) memo[v] = true;
  }

  vector<int> primes;
  primes.reserve(n - 1);
  for (int i = 2; i <= n; i++) {
    if (!memo[i]) primes.push_back(i);
  }

  int ans = 0;
  int sum = 0;
  auto left = primes.data();
  auto right = left;
  auto end = left + primes.size();
  for (;;) {
    if (sum < n) {
      if (right == end) break;
      sum += *(right++);
    } else {
      if (left == end) break;
      sum -= *(left++);
    }

    if (sum == n) ++ans;
  }

  cout << ans << "\n";

  return 0;
}
