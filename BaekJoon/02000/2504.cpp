// Title : 괄호의 값
// Link  : https://www.acmicpc.net/problem/2504 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int64_t x = 1, ans = 0;
  vector<char> memo;
  char last;
  for (auto c : s) {
    switch (c) {
      case '(': {
        x *= 2;
        memo.push_back(c);
      } break;
      case ')': {
        if (memo.empty() || memo.back() != '(') {
          cout << "0";
          return 0;
        }
        if (last == '(') ans += x;
        x /= 2;
        memo.pop_back();
      } break;
      case '[': {
        x *= 3;
        memo.push_back(c);
      } break;
      case ']': {
        if (memo.empty() || memo.back() != '[') {
          cout << "0";
          return 0;
        }
        if (last == '[') ans += x;
        x /= 3;
        memo.pop_back();
      } break;
    }
    last = c;
  }

  if (memo.empty()) {
    cout << ans;
  } else {
    cout << "0";
  }

  return 0;
}
