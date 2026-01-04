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
    if (cnt & 1) {
      int half = (cnt + 1) >> 1;
      int ub = min<int>(half, t + 1);
      key = s[idx];
      for (int i = 0; i < ub; i++) {
        s[idx + i] = key;
        s[nxt - i - 1] = key;
      }
      for (int i = ub; i < half; i++) {
        key ^= 3;
        s[idx + i] = key;
        s[nxt - i - 1] = key;
      }
    } else {
      int half = cnt >> 1;
      int ub = min<int>(half, t + 1);
      key = s[idx];
      for (int i = 0; i < ub; i++) {
        s[idx + i] = key;
        s[nxt - i - 1] = key ^ 3;
      }
      for (int i = ub; i < half; i++) {
        key ^= 3;
        s[idx + i] = key;
        s[nxt - i - 1] = key ^ 3;
      }
    }
    idx = nxt;
  }
  cout << s;

  return 0;
}