// Title : ［P］ Peeling Primes
// Link  : https://www.acmicpc.net/problem/33720
// Time  : 4 ms
// Memory: 2032 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  if (n & 1) {
    int64_t d = 3, rt = (int64_t)sqrtl((long double)n);
    while (d <= rt && n % d != 0) d += 2;
    cout << (d > rt ? 1 : ((n - d) >> 1) + 1);
  } else {
    cout << (n >> 1);
  }

  return 0;
}
