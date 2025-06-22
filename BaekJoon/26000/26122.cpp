// Title : 가장 긴 막대 자석
// Link  : https://www.acmicpc.net/problem/26122 
// Time  : 0 ms
// Memory: 2912 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;
  int idx = 0, old = 0, maxx = 0;
  while (idx < n) {
    int nxt = idx;
    while (nxt < n && s[idx] == s[nxt]) ++nxt;
    int cur = nxt - idx;
    maxx = max<int>(maxx, min<int>(old, cur));
    idx = nxt, old = cur;
  }
  cout << (maxx << 1);

  return 0;
}
