#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (;;) {
    string s;
    cin >> s;
    if (s == "0") break;
    auto b = s.data();
    auto e = b + s.size() - 1;
    bool ok = true;
    while (b <= e) {
      if (*b++ == *e--) continue;
      ok = false;
      break;
    }
    cout << (ok ? "yes\n" : "no\n");
  }

  return 0;
}
