// Title : Rectangle and Squares
// Link  : https://www.acmicpc.net/problem/13035 
// Time  : 4 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t a, b, c;
    cin >> a >> b >> c;
    int64_t x = a * b, y = c * c;

    if (x < y) {
      cout << y << "\n";
      continue;
    }

    int64_t z = x / y * y;
    if (abs(z - x) > abs(z + y - x)) z += y;
    cout << z << "\n";
  }

  return 0;
}
