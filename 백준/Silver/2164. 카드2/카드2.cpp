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
