// Title : 합성함수와 쿼리
// Link  : https://www.acmicpc.net/problem/17435 
// Time  : 148 ms
// Memory: 16864 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 19;

int table[200001][kMax];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> table[i][0];
  }

  for (int j = 1; j < kMax; j++) {
    for (int i = 1; i <= n; i++) {
      table[i][j] = table[table[i][j - 1]][j - 1];
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    bitset<kMax> bits(a);
    for (int i = 0; i < kMax; i++) {
      if (!bits.test(i)) continue;
      b = table[b][i];
    }
    cout << b << "\n";
  }

  return 0;
}
