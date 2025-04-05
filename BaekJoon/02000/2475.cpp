// Title : 검증수
// Link  : https://www.acmicpc.net/problem/2475
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int ans = 0;
  for (int i = 0; i < 5; i++) {
    int v;
    cin >> v;
    ans += v * v;
  }
  cout << ans % 10;

  return 0;
}
