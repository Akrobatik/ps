// Title : Communication Channels
// Link  : https://www.acmicpc.net/problem/11121
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    cout << (s1.compare(s2) == 0 ? "OK\n" : "ERROR\n");
  }

  return 0;
}
