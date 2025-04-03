#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a = 0, b = 0, n;
  string s;
  cin >> n >> s;
  for (auto c : s) {
    if (c == 'A') {
      ++a;
    } else {
      ++b;
    }
  }

  if (a == b) {
    cout << "Tie";
  } else if (a > b) {
    cout << "A";
  } else {
    cout << "B";
  }

  return 0;
}
