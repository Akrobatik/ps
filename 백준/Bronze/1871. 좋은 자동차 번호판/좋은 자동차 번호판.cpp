#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (int i = 0; i < 3; i++) {
      x = x * 26 + s[i] - 'A';
    }
    for (int i = 4; i < 8; i++) {
      y = y * 10 + s[i] - '0';
    }
    cout << (abs(x - y) <= 100 ? "nice\n" : "not nice\n");
  }

  return 0;
}
