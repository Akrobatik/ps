#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 1000000009;

int64_t memo[100001][3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memo[1][0] = 1;
  memo[2][1] = 1;
  memo[3][0] = memo[3][1] = memo[3][2] = 1;
  for (int i = 4; i <= 100000; i++) {
    memo[i][0] = (memo[i - 1][1] + memo[i - 1][2]) % kMod;
    memo[i][1] = (memo[i - 2][0] + memo[i - 2][2]) % kMod;
    memo[i][2] = (memo[i - 3][0] + memo[i - 3][1]) % kMod;
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int64_t sum = 0;
    for (int i = 0; i < 3; i++) sum += memo[n][i];
    cout << sum % kMod << "\n";
  }

  return 0;
}
