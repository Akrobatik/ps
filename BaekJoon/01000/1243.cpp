// Title : 팰린드롬
// Link  : https://www.acmicpc.net/problem/1243 
// Time  : 0 ms
// Memory: 2636 KB

#include <bits/stdc++.h>

using namespace std;

int memo[101][50][31];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<string> strs;
  strs.reserve(n);
  while (n--) {
    string s;
    cin >> s;
    if (s.size() <= k) strs.push_back(s);
  }
  n = strs.size();

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
      if (ok) memo[ni][i][r - l + 15] += 1;
    }
    for (int j = 0; j < ni; j++) {
      int l = j, r = ni - j - 1;
      int minn = min<int>(l, r);
      bool ok = true;
      for (int k = 0; ok && k < minn; k++) {
        ok = (is[j - k - 1] == is[j + k + 1]);
      }
      if (ok) memo[ni][i][r - l + 15] += 1;
    }
  }

  for (int i = 1; i < k; i++) {
    for (int j = 0; j < n; j++) {
      auto& js = strs[j];
      int nj = js.size();
      for (int l = -nj; l <= nj; l++) {
        auto cur = memo[i][j][l + 15];
        if (!cur) continue;

        for (int m = 0; m < n; m++) {
          auto& ms = strs[m];
          int nm = ms.size();
          int nxt = i + nm;
          if (nxt > k) continue;

          if (l < 0) {
            int minn = min<int>(-l, nm);
            bool ok = true;
            for (int o = 0; ok && o < minn; o++) {
              ok = (js[-l - o - 1] == ms[o]);
            }
            if (ok) memo[nxt][minn < nm ? m : j][l + nm + 15] += cur;
          } else {
            int minn = min<int>(l, nm);
            bool ok = true;
            for (int o = 0; ok && o < minn; o++) {
              ok = (js[nj - l + o] == ms[nm - o - 1]);
            }
            if (ok) memo[nxt][minn < nm ? m : j][l - nm + 15] += cur;
          }
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += memo[k][i][15];
  }
  cout << ans;

  return 0;
}
