// Title : Contact
// Link  : https://www.acmicpc.net/problem/1013
// Time  : 28 ms
// Memory: 2172 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    regex re("^(100+1+|01)+$");
    cout << (regex_match(s, re) ? "YES" : "NO") << endl;
  }

  return 0;
}