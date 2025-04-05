// Title : 정수 삼각형
// Link  : https://www.acmicpc.net/problem/1932
// Time  : 8 ms
// Memory: 3000 KB

#include <bits/stdc++.h>

using namespace std;

int memo[501][501];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      int v;
      cin >> v;
      memo[i][j] = v + max<int>(memo[i - 1][j], memo[i - 1][j - 1]);
    }
  }

  cout << *max_element(memo[n] + 1, memo[n] + n + 1) << endl;

  return 0;
}
