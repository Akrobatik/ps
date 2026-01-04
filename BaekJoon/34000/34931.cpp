// Title : PLATiNA::LAB
// Link  : https://www.acmicpc.net/problem/34931 
// Time  : 12 ms
// Memory: 3680 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  string s;
  cin >> n >> t >> s;

  int idx = 0;
  while (idx < n) {
    int nxt = idx, key = s[idx];
    while (nxt < n && key == s[nxt]) ++nxt, key ^= 3;

    int cnt = nxt - idx;
    int half = (cnt + 1) >> 1;
    int ub = min<int>(half, t + 1);
    int akey = s[idx], bkey = (cnt & 1) ? 0 : 3;
    for (int i = 0; i < ub; i++) {
      s[idx + i] = akey;
      s[nxt - i - 1] = akey ^ bkey;
    }
    for (int i = ub; i < half; i++) {
      akey ^= 3;
      s[idx + i] = akey;
      s[nxt - i - 1] = akey ^ bkey;
    }
    idx = nxt;
  }
  cout << s;

  return 0;
}