// Title : RGB거리
// Link  : https://www.acmicpc.net/problem/1149 
// Time  : 0 ms
// Memory: 2032 KB

#include <bits/stdc++.h>

using namespace std;

int n;
int memo[1001][3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int r, g, b;
    cin >> r >> g >> b;
    memo[i][0] = r + min<int>(memo[i - 1][1], memo[i - 1][2]);
    memo[i][1] = g + min<int>(memo[i - 1][0], memo[i - 1][2]);
    memo[i][2] = b + min<int>(memo[i - 1][0], memo[i - 1][1]);
  }

  cout << *min_element(memo[n], memo[n] + 3) << endl;

  return 0;
}
