// Title : 벌집
// Link  : https://www.acmicpc.net/problem/2292
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  --n;

  int ans = 1;
  int delta = 0;
  while (n > 0) {
    n -= (delta += 6);
    ++ans;
  }
  cout << ans;

  return 0;
}
