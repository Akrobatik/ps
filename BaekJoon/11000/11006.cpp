// Title : 남욱이의 닭장
// Link  : https://www.acmicpc.net/problem/11006
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
    cout << (b << 1) - a << " " << b - (b << 1) + a << "\n";
  }

  return 0;
}
