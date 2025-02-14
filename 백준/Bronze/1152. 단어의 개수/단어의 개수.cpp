#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  getline(cin, s);

  if (s.back() == ' ') s.pop_back();
  if (s.empty()) {
    cout << 0;
    return 0;
  }

  string_view sv(s.data() + (s.front() == ' '));
  int cnt = 1;
  for (auto c : sv) {
    if (c == ' ') ++cnt;
  }
  cout << cnt;

  return 0;
}
