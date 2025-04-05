// Title : 암호
// Link  : https://www.acmicpc.net/problem/1718
// Time  : 0 ms
// Memory: 2168 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  getline(cin, s1);
  cin >> s2;

  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == ' ') {
      cout << ' ';
    } else if (isalpha(s1[i])) {
      int key = s2[i % s2.size()] - 'a' + 1;
      cout << (char)((s1[i] - 'a' + 26 - key) % 26 + 'a');
    }
  }

  return 0;
}
