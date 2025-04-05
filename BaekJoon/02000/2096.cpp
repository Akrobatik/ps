// Title : 내려가기
// Link  : https://www.acmicpc.net/problem/2096
// Time  : 20 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int memo[2][6];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    memo[1][0] = a + min<int>(memo[0][0], memo[0][1]);
    memo[1][1] = b + min<int>(memo[0][0], min<int>(memo[0][1], memo[0][2]));
    memo[1][2] = c + min<int>(memo[0][1], memo[0][2]);
    memo[1][3] = a + max<int>(memo[0][3], memo[0][4]);
    memo[1][4] = b + max<int>(memo[0][3], max<int>(memo[0][4], memo[0][5]));
    memo[1][5] = c + max<int>(memo[0][4], memo[0][5]);
    memcpy(memo[0], memo[1], 24);
  }

  cout << *max_element(memo[0] + 3, memo[0] + 6) << " "
       << *min_element(memo[0], memo[0] + 3) << endl;

  return 0;
}
