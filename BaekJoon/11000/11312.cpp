// Title : 삼각 무늬 － 2
// Link  : https://www.acmicpc.net/problem/11312
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t a, b;
    cin >> a >> b;
    int64_t x = (a / b) + (a % b != 0);
    cout << x * x << "\n";
  }

  return 0;
}
