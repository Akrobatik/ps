// Title : 걷다보니 신천역 삼 （Small）
// Link  : https://www.acmicpc.net/problem/14650
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int memo[10][3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  int ans = 2;
  for (int i = 2; i < n; i++) {
    ans *= 3;
  }
  cout << ans;

  return 0;
}
