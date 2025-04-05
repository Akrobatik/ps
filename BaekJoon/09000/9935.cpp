// Title : 문자열 폭발
// Link  : https://www.acmicpc.net/problem/9935
// Time  : 16 ms
// Memory: 5224 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;
  vector<char> vec;
  int idx = 0;
  bool frula = true;
  for (char c : s1) {
    if (c == s2[idx]) {
      vec.push_back(c);
      if (++idx == s2.size()) {
        vec.erase(vec.end() - s2.size(), vec.end());
        idx = vec.empty() ? 0
                          : distance(s2.begin(), find(s2.begin(), s2.end(), vec.back())) + 1;
      }
    } else if (idx > 0 && c == s2[0]) {
      vec.push_back(c);
      idx = 1;
    } else {
      if (vec.empty()) {
        cout << c;
      } else {
        cout << string_view(vec.data(), vec.size()) << c;
        vec.clear();
        idx = 0;
      }
      frula = false;
    }
  }

  if (!vec.empty())
    cout << string_view(vec.data(), vec.size()) << "\n";
  else
    cout << (frula ? "FRULA\n" : "\n");

  return 0;
}
