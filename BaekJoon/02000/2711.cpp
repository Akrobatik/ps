// Title : 오타맨 고창영
// Link  : https://www.acmicpc.net/problem/2711 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    --n;
    for (int i = 0; i < s.size(); i++) {
      if (i == n) continue;
      cout << s[i];
    }
    cout << "\n";
  }

  return 0;
}
