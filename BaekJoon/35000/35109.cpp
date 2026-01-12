// Title : ^&^
// Link  : https://www.acmicpc.net/problem/35109 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  if (s == "10") {
    cout << "0";
    return 0;
  }

  int cnt = count(s.begin(), s.end(), '1');
  if (s.back() == '1') {
    cout << s;
  } else if (cnt + 1 == s.size() && s.back() == '0') {
    s[s.size() - 2] = '0';
    cout << s;
  } else {
    for (auto& c : s) c = '1';
    cout << s;
  }

  return 0;
}