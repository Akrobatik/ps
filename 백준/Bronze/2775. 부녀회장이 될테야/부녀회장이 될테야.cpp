#include <bits/stdc++.h>

using namespace std;

template <int N>
  requires(N >= 1)
struct Table {
  constexpr Table() {
    for (int i = 0; i <= N; i++) table[0][i] = i;
    for (int i = 1; i <= N; i++) {
      int sum = 0;
      for (int j = 0; j <= N; j++) table[i][j] = (sum += table[i - 1][j]);
    }
  }

  constexpr int operator()(int k, int n) const {
    return table[k][n];
  }

  int table[N + 1][N + 1];
};

constexpr Table<14> kTable;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int k, n;
    cin >> k >> n;
    cout << kTable(k, n) << "\n";
  }

  return 0;
}
