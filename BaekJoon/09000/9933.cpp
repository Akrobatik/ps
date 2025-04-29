// Title : 민균이의 비밀번호
// Link  : https://www.acmicpc.net/problem/9933 
// Time  : 0 ms
// Memory: 2160 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  set<string> memo;

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    if (!memo.insert(s).second) {
      cout << s.size() << " " << s[s.size() >> 1];
      return 0;
    }
    reverse(s.begin(), s.end());
    if (!memo.insert(s).second) {
      cout << s.size() << " " << s[s.size() >> 1];
      return 0;
    }
  }

  return 0;
}
