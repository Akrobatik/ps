// Title : 쿠키애호가
// Link  : https://www.acmicpc.net/problem/11134
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
    cout << (a / b) + (a % b != 0) << "\n";
  }

  return 0;
}
