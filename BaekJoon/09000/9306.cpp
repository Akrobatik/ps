// Title : Practice: Roll Call
// Link  : https://www.acmicpc.net/problem/9306 
// Time  : 0 ms
// Memory: 2380 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    cout << format("Case {}: {}, {}\n", i, s2, s1);
  }

  return 0;
}