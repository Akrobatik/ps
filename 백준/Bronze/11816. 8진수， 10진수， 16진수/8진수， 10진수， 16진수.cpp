#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  if (s.starts_with("0x")) {
    cout << stoi(s, 0, 16);
  } else if (s.starts_with("0")) {
    cout << stoi(s, 0, 8);
  } else {
    cout << stoi(s, 0, 10);
  }

  return 0;
}
