#include <bits/stdc++.h>

using namespace std;

template <int N>
  requires(N >= 1)
struct PrimeTable {
  constexpr PrimeTable() {
    fill(table, table + N + 1, true);
    table[0] = table[1] = false;
    for (int i = 2; i <= 32; i++) {
      if (!table[i]) continue;
      for (int j = (i << 1); j <= N; j += i) table[j] = false;
    }
  }

  constexpr bool operator()(int n) const {
    return table[n];
  }

  bool table[N + 1];
};

constexpr PrimeTable<1000> kPrime;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  --n;

  int ans = 1;
  int delta = 0;
  while (n > 0) {
    n -= (delta += 6);
    ++ans;
  }
  cout << ans;

  return 0;
}
