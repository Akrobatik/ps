// Title : Inverse Look-and-Say
// Link  : https://www.acmicpc.net/problem/34682 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int n = s.size();
  if (n & 1) {
    cout << "-1";
    return 0;
  }

  string ans;
  int prv = 0;
  for (int i = 0; i < n; i += 2) {
    int cnt = s[i] - '0';
    if (cnt == 0 || prv == s[i + 1]) {
      cout << "-1";
      return 0;
    }
    prv = s[i + 1];

    ans.append(string(cnt, s[i + 1]));
  }

  if (ans.empty() || ans[0] == '0') {
    cout << "-1";
    return 0;
  }
  cout << ans;

  return 0;
}