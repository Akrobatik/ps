#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t memo[101] = {0, 1, 1, 1, 2, 2};
  for (int i = 6; i <= 100; i++) {
    memo[i] = memo[i - 1] + memo[i - 5];
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
