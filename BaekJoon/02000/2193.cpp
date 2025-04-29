// Title : 이친수
// Link  : https://www.acmicpc.net/problem/2193 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int64_t Comb(int n, int r) {
  __int128_t res = 1;
  for (int i = 0; i < r; i++) {
    res = res * (n - i) / (i + 1);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int64_t sum = 0;
  int limit = (n + 1) >> 1;
  for (int i = 1; i <= limit; i++) {
    int r = n - (i << 1) + 1;
    sum += Comb(i + r - 1, r);
  }
  cout << sum;

  return 0;
}
