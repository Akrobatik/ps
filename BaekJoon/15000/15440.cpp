// Title : Vera And LCS
// Link  : https://www.acmicpc.net/problem/15440 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  string s;
  cin >> n >> k >> s;
  int cnt[26] = {};
  for (auto c : s) ++cnt[c - 'a'];

  int minn = INT_MAX, mchar;
  for (int i = 0; i < 26; i++) {
    if (minn > cnt[i]) minn = cnt[i], mchar = i;
  }

  if (minn <= k && k <= n) {
    string ans(n, mchar + 'a');
    int rem = k - minn;
    for (int i = n - 1; rem && i >= 0; i--) {
      if (ans[i] == s[i]) continue;
      ans[i] = s[i];
      --rem;
    }
    cout << ans;
  } else {
    cout << "WRONGANSWER";
  }

  return 0;
}
