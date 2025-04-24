// Title : 문자열 비교하기
// Link  : https://www.acmicpc.net/problem/17180 
// Time  : 0 ms
// Memory: 2380 KB

#include <bits/stdc++.h>

using namespace std;

int memo[301][301];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fill_n((int*)memo, 301 * 301, INT_MAX >> 1);

  int n1, n2;
  string s1, s2;
  cin >> n1 >> n2 >> s1 >> s2;

  memo[0][0] = 0;
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      memo[i][j] = min<int>({memo[i - 1][j - 1], memo[i - 1][j], memo[i][j - 1]}) + abs(s1[i - 1] - s2[j - 1]);
    }
  }
  cout << memo[n1][n2];

  return 0;
}
