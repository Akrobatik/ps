// Title : SCSC 기차 놀이
// Link  : https://www.acmicpc.net/problem/33967 
// Time  : 0 ms
// Memory: 2648 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  int cnt = s.size() - 1;
  for (int i = 1; i < s.size(); i++) {
    if (s[i - 1] == s[i]) {
      if (s[i] == '5' || s[i] == '2') ++cnt;
    }
    if (s[i - 1] == ']' && s[i] == '[') --cnt;
  }
  cout << cnt;

  return 0;
}
