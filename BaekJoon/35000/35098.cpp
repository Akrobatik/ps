// Title : Prefix and Suffix Can Be the Same
// Link  : https://www.acmicpc.net/problem/35098 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  while (cin >> n >> s) {
    int len;
    for (int i = 0; i < n; i++) {
      bool ok = true;
      for (int j = 0; ok && j < i; j++) {
        ok = (s[j] == s[n - i + j]);
      }
      if (ok) len = i;
    }

    cout << s;
    for (int i = len; i < n; i++) cout << s[i];
    cout << "\n";
  }

  return 0;
}