// Title : 비장의 일격 （Large）
// Link  : https://www.acmicpc.net/problem/33716
// Time  : 224 ms
// Memory: 210712 KB

#include <bits/stdc++.h>

using namespace std;

int nxts[1000000];
int memo[1000000][26][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int prvs[26];
  memset(prvs, -1, sizeof(prvs));

  int n, k;
  string s;
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'X') continue;
    int x = s[i] - 'A';
    if (prvs[x] != -1) nxts[prvs[x]] = i;
    prvs[x] = i;
  }

  k = min<int>(k, 25);
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j <= k; j++) {
      memo[i + 1][j][0] = max<int>({memo[i + 1][j][0], memo[i][j][0], memo[i][j][1]});
    }

    int nxt = nxts[i];
    if (nxt) {
      for (int j = 0; j < k; j++) {
        memo[nxt][j + 1][1] = max<int>({memo[nxt][j + 1][1], memo[i][j][0] + nxt - i + 1, memo[i][j + 1][1] + nxt - i});
      }
    }
  }
  cout << n - max<int>(memo[n - 1][k][0], memo[n - 1][k][1]);

  return 0;
}
