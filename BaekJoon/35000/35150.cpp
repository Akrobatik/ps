// Title : 동우의 생일은?
// Link  : https://www.acmicpc.net/problem/35150 
// Time  : 32 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t a, b, n;
    cin >> a >> b >> n;

    int64_t x = n >> 1, y = n - x;
    cout << (a * x + b * y) * (a * y + b * x) << "\n";
  }

  return 0;
}