#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1000000000;

int64_t memo[2][10][1 << 10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= 9; i++) memo[0][i][1 << i] = 1;

  auto m = memo[1], m_old = memo[0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 1024; j++) {
      m[0][j | (1 << 0)] += m_old[1][j];
      m[9][j | (1 << 9)] += m_old[8][j];
      for (int k = 1; k <= 8; k++) {
        m[k][j | (1 << k)] += m_old[k - 1][j];
        m[k][j | (1 << k)] += m_old[k + 1][j];
      }
    }

    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k < 1024; k++) m[j][k] %= kMod;
    }

    swap(m, m_old);
    memset(m, 0, sizeof(memo[0]));
  }

  int64_t sum = 0;
  for (int i = 0; i <= 9; i++) {
    sum += m_old[i][1023];
  }
  cout << sum % kMod;

  return 0;
}
