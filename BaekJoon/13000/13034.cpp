// Title : 다각형 게임
// Link  : https://www.acmicpc.net/problem/13034 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int memo[1001] = {0, 0, 1};

  int n;
  cin >> n;
  for (int i = 3; i <= n; i++) {
    int nxt[1001] = {};
    int mid = i >> 1;
    for (int j = 0; j <= mid; j++) {
      int l = j, r = i - l - 2;
      nxt[memo[l] ^ memo[r]] = 1;
    }
    for (int j = 0; j < i; j++) {
      if (nxt[j]) continue;
      memo[i] = j;
      break;
    }
  }

  cout << (char)('1' + (memo[n] == 0));

  return 0;
}
