// Title : 피보나치 수
// Link  : https://www.acmicpc.net/problem/2747 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  __int128_t memo[46];
  memo[1] = 1;
  for (int i = 2; i <= 45; i++) memo[i] = memo[i - 1] + memo[i - 2];

  int n;
  cin >> n;
  char tmp[64];
  int nt = 0;
  __int128_t x = memo[n];
  while (x) tmp[nt++] = x % 10 + '0', x /= 10;
  while (nt--) cout << tmp[nt];

  return 0;
}
