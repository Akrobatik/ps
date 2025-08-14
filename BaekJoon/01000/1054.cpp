// Title : 팰린드롬 문장
// Link  : https://www.acmicpc.net/problem/1054 
// Time  : 76 ms
// Memory: 24488 KB

#include <bits/stdc++.h>

using namespace std;

int64_t memo[1 << 13][13][27];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> strs(n);
  for (auto& s : strs) cin >> s;

  for (int i = 0; i < n; i++) {
    auto& is = strs[i];
    int ni = is.size();
    for (int j = 0; j < ni; j++) {
      int l = j, r = ni - j;
      int minn = min<int>(l, r);
      bool ok = true;
      for (int k = 0; ok && k < minn; k++) {
        ok = (is[j - k - 1] == is[j + k]);
      }
      if (ok) memo[1 << i][i][r - l + 13] = 1;
    }
    for (int j = 0; j < ni; j++) {
      int l = j, r = ni - j - 1;
      int minn = min<int>(l, r);
      bool ok = true;
      for (int k = 0; ok && k < minn; k++) {
        ok = (is[j - k - 1] == is[j + k + 1]);
      }
      if (ok) memo[1 << i][i][r - l + 13] = 1;
    }
  }

  int limit = 1 << n;
  for (int i = 0; i < limit; i++) {
    for (int j = 0; j < n; j++) {
      auto& js = strs[j];
      int nj = js.size();
      for (int k = -nj; k <= nj; k++) {
        int64_t cur = memo[i][j][k + 13];
        if (cur == 0) continue;

        for (int l = 0; l < n; l++) {
          int b = 1 << l;
          if (i & b) continue;

          auto& ls = strs[l];
          int nl = ls.size();
          if (k < 0) {
            int minn = min<int>(-k, nl);
            bool ok = true;
            for (int m = 0; ok && m < minn; m++) {
              ok = (js[-k - m - 1] == ls[m]);
            }
            if (ok) memo[i | b][minn < nl ? l : j][k + nl + 13] += cur;
          } else {
            int minn = min<int>(k, nl);
            bool ok = true;
            for (int m = 0; ok && m < minn; m++) {
              ok = (js[nj - k + m] == ls[nl - m - 1]);
            }
            if (ok) memo[i | b][minn < nl ? l : j][k - nl + 13] += cur;
          }
        }
      }
    }
  }

  int64_t ans = 0;
  for (int i = 0; i < limit; i++) {
    for (int j = 0; j < n; j++) {
      ans += memo[i][j][13];
    }
  }
  cout << ans;

  return 0;
}
