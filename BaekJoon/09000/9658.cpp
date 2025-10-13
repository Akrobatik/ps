// Title : 돌 게임 4
// Link  : https://www.acmicpc.net/problem/9658 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int memo[1001] = {1};
  for (int i = 1; i <= n; i++) {
    for (int j : {1, 3, 4}) {
      if (i - j >= 0 && !memo[i - j]) {
        memo[i] = 1;
        break;
      }
    }
  }
  cout << (memo[n] ? "SK" : "CY");

  return 0;
}