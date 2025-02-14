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
  int minn = n - (log10(n) + 1) * 9;
  for (int i = minn; i < n; i++) {
    int v = i;
    int sum = v;
    while (v) {
      auto dv = div(v, 10);
      sum += dv.rem;
      v = dv.quot;
    }
    if (sum == n) {
      cout << i;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
