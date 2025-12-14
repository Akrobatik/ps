// Title : MIT and TIM
// Link  : https://www.acmicpc.net/problem/34903 
// Time  : 12 ms
// Memory: 3168 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<pair<int, int>> arr;

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    arr.clear();
    int n = s.size(), idx = 0;
    while (idx < n) {
      if (s[idx] == 'I') {
        ++idx;
      } else {
        int nxt = idx;
        while (nxt < n && (nxt - idx) % 2 == (s[nxt] == 'I' ? 1 : 0)) ++nxt;

        int len = nxt - idx;
        if (~len & 1) --len;
        arr.push_back({idx, idx + len - 1});
        idx = nxt;
      }
    }

    int cnt = 0;
    for (auto [st, en] : arr) {
      int len = en - st + 1;
      int mc = 0, mt = 0;
      for (int i = st; i <= en; i++) {
        mc += (s[i] == 'M');
        mt += (s[i] == 'T');
      }
      cnt += min<int>({mc, mt / 2, (len + 1) / 6});
    }
    cout << cnt << "\n";
  }

  return 0;
}