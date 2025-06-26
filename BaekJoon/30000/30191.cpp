// Title : 문자열 만들기 1
// Link  : https://www.acmicpc.net/problem/30191 
// Time  : 16 ms
// Memory: 6152 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  string ans;
  ans.reserve(n << 1);

  vector<char> stk;
  constexpr char kXor = 'S' ^ 'U';
  for (auto c : views::reverse(s)) {
    if (stk.empty() || c == stk.back()) {
      ans.push_back(c ^ kXor);
      ans.push_back('N');
      stk.push_back(c);
    } else {
      ans.push_back('N');
      stk.pop_back();
    }
  }

  cout << ans.size() << "\n"
       << ans;

  return 0;
}
