#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l;
  cin >> n >> l;

  int cnt = 0;
  for (int i = 1;; i++) {
    string s = to_string(i);
    bool ok = true;
    for (auto c : s) {
      if (c == l + '0') {
        ok = false;
        break;
      }
    }

    if (ok && ++cnt == n) {
      cout << i;
      return 0;
    }
  }

  return 0;
}
