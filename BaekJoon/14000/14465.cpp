// Title : 소가 길을 건너간 이유 5
// Link  : https://www.acmicpc.net/problem/14465
// Time  : 0 ms
// Memory: 2216 KB

#include <bits/stdc++.h>

using namespace std;

int8_t memo[200001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, b;
  cin >> n >> k >> b;
  while (b--) {
    int x;
    cin >> x;
    memo[x] = memo[x + n] = 1;
  }

  int cur = 0;
  for (int i = 1; i <= k; i++) cur += memo[i];
  int ans = cur;
  for (int i = 1; i <= n - k; i++) {
    cur += memo[i + k] - memo[i];
    if (ans > cur) ans = cur;
  }
  cout << ans;

  return 0;
}
