// Title : toycppartoon
// Link  : https://www.acmicpc.net/problem/34991 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  string ans;
  int n = s.size(), maxx = 0;
  for (int i = 0; i < 10; i++) {
    int m = min<int>(n, 10);
    for (int lr = 1; lr <= m; lr++) {
      for (int l = 1; l <= lr; l++) {
        int r = lr - l;
        bool ok = true;
        for (int j = 0; j < l; j++) {
          ok &= ("toycartoon"[i + j] == s[j]);
        }
        for (int j = 0; j < r; j++) {
          ok &= ("toycartoon"[i + lr - j - 1] == s[n - j - 1]);
        }
        if (ok && maxx < lr && n + 10 - lr <= 20) {
          maxx = lr;
          ans.clear();
          for (int j = 0; j < i; j++) ans.push_back("toycartoon"[j]);
          ans.append(s);
          for (int j = i + lr; j < 10; j++) ans.push_back("toycartoon"[j]);
        }
      }
    }
  }

  if (ans.empty()) {
    if (n <= 9) {
      ans = "toycartoon_" + s;
    } else {
      ans = "toycartoon";
    }
  }
  cout << ans;

  return 0;
}