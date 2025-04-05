// Title : 꿍 가라사대
// Link  : https://www.acmicpc.net/problem/11094
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int t;
  cin >> t;
  getline(cin, s);
  while (t--) {
    getline(cin, s);
    if (s.starts_with("Simon says")) {
      cout << s.substr(10) << "\n";
    }
  }

  return 0;
}
