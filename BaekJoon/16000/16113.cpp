// Title : 시그널
// Link  : https://www.acmicpc.net/problem/16113 
// Time  : 0 ms
// Memory: 2392 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  int m = n / 5;
  vector<vector<bool>> mat(5, vector<bool>(m));
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i * m + j] == '#') mat[i][j] = true;
    }
  }

  auto Check = [&](int col) {
    for (int i = 0; i < 5; i++) {
      if (mat[i][col]) return true;
    }
    return false;
  };

  auto Get = [&](int l, int r) {
    int sz = r - l;
    if (sz == 1) return 1;

    int cnt = 0;
    for (int i = 0; i < 5; i++) {
      for (int j = l; j < r; j++) {
        cnt += mat[i][j];
      }
    }

    if (cnt == 7) return 7;
    if (cnt == 9) return 4;
    if (cnt == 13) return 8;

    if (cnt == 11) {
      if (mat[1][l + 2] && mat[3][l]) return 2;
      if (mat[1][l + 2] && mat[3][l + 2]) return 3;
      return 5;
    }

    if (!mat[1][l + 2]) return 6;
    if (!mat[3][l]) return 9;
    return 0;
  };

  vector<pair<int, int>> arr;
  int idx = 0;
  while (idx < m) {
    if (!Check(idx)) {
      ++idx;
      continue;
    }

    int nxt = idx;
    while (nxt < m && Check(nxt)) ++nxt;

    cout << Get(idx, nxt);
    idx = nxt;
  }

  return 0;
}
