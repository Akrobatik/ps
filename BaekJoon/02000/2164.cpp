// Title : 카드2
// Link  : https://www.acmicpc.net/problem/2164
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int msb = 1 << (bit_width((unsigned int)n) - 1);
  if (n == msb) {
    cout << n;
  } else {
    cout << ((n ^ msb) << 1);
  }

  return 0;
}
