// Title : 팰린드롬수
// Link  : https://www.acmicpc.net/problem/1259 
// Time  : 0 ms
// Memory: 2024 KB

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
