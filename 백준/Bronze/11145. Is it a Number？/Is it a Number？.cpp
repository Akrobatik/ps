#include <bits/stdc++.h>

using namespace std;

void Trim(string& s) {
  auto b = find_if_not(s.begin(), s.end(), ::isspace);
  auto e = find_if_not(s.rbegin(), s.rend(), ::isspace).base();
  if (b < e) {
    s = string(b, e);
  } else {
    s.clear();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  regex re("^\\d+$");

  string s;
  int t;
  cin >> t;
  getline(cin, s);
  while (t--) {
    getline(cin, s);
    Trim(s);
    if (regex_match(s, re)) {
      auto b = s.find_first_not_of('0');
      if (b == string::npos) {
        s = "0";
      } else {
        s = s.substr(b);
      }
      cout << s << "\n";
    } else {
      cout << "invalid input\n";
    }
  }

  return 0;
}
