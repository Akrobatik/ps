// Title : 과제가 너무 많아
// Link  : https://www.acmicpc.net/problem/30867 
// Time  : 4 ms
// Memory: 2648 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  string s;
  cin >> n >> m >> s;

  int idx = 0;
  while (idx < n) {
    while (idx < n && s[idx] != 'w' && s[idx] != 'h') ++idx;
    int nxt = idx + 1;
    while (nxt < n && (s[nxt] == 'w' || s[nxt] == 'h')) ++nxt;

    int cnt = 0;
    for (int i = idx; i < nxt; i++) {
      if (s[i] != 'h') continue;
      int d = i - (idx + cnt++);
      swap(s[i - min<int>(d, m)], s[i]);
    }

    idx = nxt;
  }
  cout << s;

  return 0;
}