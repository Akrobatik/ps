#include <bits/stdc++.h>

using namespace std;

int Power(int n, int exp) {
  if (exp == 1) return n;
  int nn = Power(n, exp >> 1);
  nn = nn * nn % 10;
  if (exp & 1) nn = nn * n % 10;
  return nn;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a % 10 == 0) {
      cout << "10\n";
    } else {
      cout << Power(a % 10, b) << "\n";
    }
  }

  return 0;
}
