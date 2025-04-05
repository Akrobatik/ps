// Title : 소수의 연속합
// Link  : https://www.acmicpc.net/problem/1644
// Time  : 60 ms
// Memory: 7044 KB

#include <bits/stdc++.h>

using namespace std;

bool memo[4000001];
int primes[283146];

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

  int *left, *right, *end;
  left = right = end = primes;
  for (int i = 2; i <= n; i++) {
    if (!memo[i]) *(end++) = i;
  }

  int ans = 0, sum = 0;
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
