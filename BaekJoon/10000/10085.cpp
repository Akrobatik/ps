// Title : Tickets
// Link  : https://www.acmicpc.net/problem/10085 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;

  string s(n, '0');
  int64_t b = 1LL << n;
  for (int i = 0; i < n; i++, b >>= 1) {
    if (k > (b >> 1)) s[i] ^= 1, k = b - k + 1;
  }
  cout << s;

  return 0;
}
