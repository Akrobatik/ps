#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1000000000;

int memo[100][10][1 << 10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= 9; i++) memo[0][i][1 << i] = 1;

  for (int i = 1; i < n; i++) {
    auto m = memo[i], m_old = memo[i - 1];
    for (int j = 0; j < 1024; j++) {
      m[0][j | (1 << 0)] = (m[0][j | (1 << 0)] + m_old[1][j]) % kMod;
      m[9][j | (1 << 9)] = (m[9][j | (1 << 9)] + m_old[8][j]) % kMod;
      for (int k = 1; k <= 8; k++) {
        m[k][j | (1 << k)] = (m[k][j | (1 << k)] + m_old[k - 1][j]) % kMod;
        m[k][j | (1 << k)] = (m[k][j | (1 << k)] + m_old[k + 1][j]) % kMod;
      }
    }
  }

  int64_t sum = 0;
  for (int i = 0; i <= 9; i++) {
    sum += memo[n - 1][i][1023];
    sum %= kMod;
  }
  cout << sum;

  return 0;
}
