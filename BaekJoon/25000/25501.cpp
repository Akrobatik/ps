// Title : 재귀의 귀재
// Link  : https://www.acmicpc.net/problem/25501 
// Time  : 4 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int cnt;

int recursion(const char *s, int l, int r) {
  ++cnt;
  if (l >= r)
    return 1;
  else if (s[l] != s[r])
    return 0;
  else
    return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s) {
  return recursion(s, 0, strlen(s) - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cnt = 0;
    int res = isPalindrome(s.c_str());
    cout << res << " " << cnt << "\n";
  }

  return 0;
}
