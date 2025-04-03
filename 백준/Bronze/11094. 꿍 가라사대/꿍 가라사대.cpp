#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int t;
  cin >> t;
  getline(cin, s);
  while (t--) {
    getline(cin, s);
    if (s.starts_with("Simon says")) {
      cout << s.substr(10) << "\n";
    }
  }

  return 0;
}
