// Title : 알약
// Link  : https://www.acmicpc.net/problem/4811 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t memo[31] = {};
  for (int i = 1; i <= 30; i++) {
    int64_t x = 1, y = i << 1;
    for (int j = 0; j < i; j++) {
      x *= y - j;
      x /= j + 1;
    }
    memo[i] = x / (i + 1);
  }

  int n;
  while (cin >> n && n) {
    cout << memo[n] << "\n";
  }

  return 0;
}