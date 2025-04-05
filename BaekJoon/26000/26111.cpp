// Title : Parentheses Tree
// Link  : https://www.acmicpc.net/problem/26111
// Time  : 88 ms
// Memory: 26720 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int64_t ans = 0;
  int n = s.size(), cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '(' && s[i + 1] == ')') {
      ans += cnt;
    }

    if (s[i] == '(') {
      ++cnt;
    } else {
      --cnt;
    }
  }
  cout << ans;

  return 0;
}
