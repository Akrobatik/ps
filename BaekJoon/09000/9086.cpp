// Title : 문자열
// Link  : https://www.acmicpc.net/problem/9086 
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
    string s;
    cin >> s;
    cout << s.front() << s.back() << "\n";
  }

  return 0;
}
