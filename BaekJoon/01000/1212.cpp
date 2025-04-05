// Title : 8진수 2진수
// Link  : https://www.acmicpc.net/problem/1212
// Time  : 12 ms
// Memory: 3636 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  if (s.size() == 1 && s[0] == '0') {
    cout << "0";
    return 0;
  }

  string ans;
  ans.reserve(s.size() * 3);
  for (int i = 0; i < s.size(); i++) {
    int n = stoi(s.substr(i, 1), 0, 8);
    bitset<3> b(n);
    for (int j = 2; j >= 0; j--) {
      ans.push_back(b.test(j) ? '1' : '0');
    }
  }

  string_view sv = ans;
  cout << sv.substr(ans.find_first_not_of('0'));

  return 0;
}
