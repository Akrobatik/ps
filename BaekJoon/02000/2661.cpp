// Title : 좋은수열
// Link  : https://www.acmicpc.net/problem/2661 
// Time  : 0 ms
// Memory: 2084 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  string s;
  s.resize(n);

  [&](this auto&& self, int idx) {
    string_view sv(s);
    int half = idx >> 1;
    for (int i = 1; i <= half; i++) {
      if (sv.substr(idx - (i << 1), i) == sv.substr(idx - i, i)) return false;
    }

    if (idx == n) return true;

    for (int i = 1; i <= 3; i++) {
      s[idx] = i + '0';
      if (self(idx + 1)) return true;
    }
    return false;
  }(0);

  cout << s;

  return 0;
}