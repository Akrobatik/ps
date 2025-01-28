#include <bits/stdc++.h>

using namespace std;

int votes[100001];
int memo[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> votes[i];
      memo[i] = 0;
    }

    int sum = 0, cnt = 1;
    for (int i = 1; i <= n; i++) {
      if (memo[i]) continue;

      int cur = i, start = cnt;
      while (memo[cur] == 0) {
        memo[cur] = cnt++;
        cur = votes[cur];
      }

      if (memo[cur] >= start) sum += cnt - memo[cur];
    }

    cout << n - sum << "\n";
  }

  return 0;
}
