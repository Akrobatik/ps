// Title : Wow
// Link  : https://www.acmicpc.net/problem/33772 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;
  int cnt = 0;
  for (int i = 1; i < s.size() - 1; i++) {
    if (s[i] == '.') {
      if (s[i - 1] != '.' && s[i + 1] != '.') {
        if (cnt == 2) {
          cout << 'v';
        } else {
          cout << 'w';
        }
        cnt = 0;
      } else {
        ++cnt;
      }
    }
  }
  if (cnt == 2) {
    cout << 'v';
  } else {
    cout << 'w';
  }

  return 0;
}
