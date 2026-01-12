// Title : 히든 이벤트
// Link  : https://www.acmicpc.net/problem/35107 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

long double Comb(int n, int r) {
  long double res = 1.0L;
  for (int i = 0; i < r; i++) {
    res *= n - i;
    res /= i + 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  int r = n - m;
  for (int i = 1; i <= k; i++) {
    if (r < i) {
      cout << "1.0\n";
    } else {
      long double prob = 1.0L;
      for (int j = 0; j < i; j++) {
        prob *= r - j;
        prob /= n - j;
      }
      cout << setprecision(6) << fixed << (1.0L - prob) << "\n";
    }
  }

  return 0;
}