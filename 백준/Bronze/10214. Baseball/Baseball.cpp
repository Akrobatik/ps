#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int a = 0, b = 0;
    for (int i = 0; i < 9; i++) {
      int aa, bb;
      cin >> aa >> bb;
      a += aa, b += bb;
    }
    if (a == b) {
      cout << "Draw\n";
    } else if (a > b) {
      cout << "Yonsei\n";
    } else {
      cout << "korea\n";
    }
  }

  return 0;
}
