// Title : LCS 2
// Link  : https://www.acmicpc.net/problem/9252
// Time  : 4 ms
// Memory: 5940 KB

#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int memo[1001][1001];

string GetString(int y, int x) {
  string s;
  int n = memo[y][x];
  s.resize(n);

  queue<pair<int, int>> q;
  q.push({y, x});
  while (!q.empty()) {
    auto [yy, xx] = q.front();
    q.pop();

    if (memo[yy][xx] > memo[yy - 1][xx - 1] &&
        memo[yy][xx] > memo[yy - 1][xx] &&
        memo[yy][xx] > memo[yy][xx - 1]) {
      s[--n] = s1[xx - 1];
      if (n == 0) break;
      q.push({yy - 1, xx - 1});
    } else if (memo[yy - 1][xx] > memo[yy][xx - 1]) {
      q.push({yy - 1, xx});
    } else {
      q.push({yy, xx - 1});
    }
  }

  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s1 >> s2;
  int n1 = s1.size(), n2 = s2.size();
  for (int y = 1; y <= n2; y++) {
    for (int x = 1; x <= n1; x++) {
      if (s2[y - 1] == s1[x - 1]) {
        memo[y][x] = memo[y - 1][x - 1] + 1;
      } else {
        memo[y][x] = max<int>(memo[y - 1][x], memo[y][x - 1]);
      }
    }
  }

  cout << memo[n2][n1] << endl;
  if (memo[n2][n1]) {
    cout << GetString(n2, n1) << endl;
  }

  return 0;
}
