// Title : 쿠폰
// Link  : https://www.acmicpc.net/problem/10179
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    double x;
    cin >> x;
    cout << "$" << setprecision(2) << fixed << round(x * 80.0) / 100.0 << "\n";
  }

  return 0;
}
