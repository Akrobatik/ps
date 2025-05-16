// Title : 초콜릿 피라미드
// Link  : https://www.acmicpc.net/problem/25793 
// Time  : 44 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t r, c;
    cin >> r >> c;
    if (r < c) swap(r, c);
    int64_t x = c * (c + 1) * ((c << 1) + 1) / 3 + c * (c * (r - c - 1) - 1);
    cout << x + c << " " << x << "\n";
  }

  return 0;
}
