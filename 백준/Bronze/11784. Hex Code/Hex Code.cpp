#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  while (cin >> s) {
    for (int i = 0; i < s.size(); i += 2) {
      int x = stoi(s.substr(i, 2), 0, 16);
      cout << (char)(x);
    }
    cout << "\n";
  }

  return 0;
}
