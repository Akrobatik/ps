// Title : 퇴사 2
// Link  : https://www.acmicpc.net/problem/15486 
// Time  : 192 ms
// Memory: 7880 KB

#include <bits/stdc++.h>

using namespace std;

int memo[1500002];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int t, p;
    cin >> t >> p;
    memo[i] = max<int>(memo[i], memo[i - 1]);
    if (i + t - 1 <= n) {
      memo[i + t] = max<int>(memo[i + t], memo[i] + p);
    }
  }
  cout << max<int>(memo[n], memo[n + 1]);

  return 0;
}
