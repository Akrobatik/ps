// Title : 오타
// Link  : https://www.acmicpc.net/problem/5875 
// Time  : 0 ms
// Memory: 2300 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  int cur = 0, minn = 0;
  for (int i = 0; i < n; i++) {
    cur += (s[i] == '(' ? 1 : -1);
    minn = min<int>(minn, cur);
  }

  if (abs(cur) != 2 || minn < -2) {
    cout << "0";
    return 0;
  }

  if (cur == 2) {
    reverse(s.begin(), s.end());
    for (auto& c : s) c ^= 1;
  }

  int cnt = 0;
  cur = 0;
  for (int i = 0; i < n; i++) {
    cur += (s[i] == '(' ? 1 : -1);
    if (s[i] == ')') ++cnt;
    if (cur == -1) {
      cout << cnt;
      break;
    }
  }

  return 0;
}