#include <bits/stdc++.h>

using namespace std;

bool memo[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n;
  cin >> m >> n;
  for (int i = 2; i <= n; i++) {
    if (memo[i]) continue;
    if (m <= i && i <= n) cout << i << "\n";
    for (int j = (i << 1); j <= n; j += i) memo[j] = true;
  }

  return 0;
}
