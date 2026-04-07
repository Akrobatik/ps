// Title : StackExplosion
// Link  : https://www.acmicpc.net/problem/35482 
// Time  : 328 ms
// Memory: 21564 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int64_t> lmt(n), val(n);
  for (auto& e : lmt) cin >> e;
  for (auto& e : val) cin >> e;

  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int lhs, int rhs) {
    int64_t lv = lmt[lhs] - val[lhs];
    int64_t rv = lmt[rhs] - val[rhs];
    return lv < rv;
  });

  int idx = 0;
  int64_t add = 0, cnt = 0;
  while (idx < n && val[ord[idx]] + add > lmt[ord[idx]]) {
    int nxt = idx;
    int64_t cadd = 0;
    while (nxt < n && val[ord[nxt]] + add > lmt[ord[nxt]]) {
      cadd += (val[ord[nxt]] + add) >> 1, ++cnt;
      ++nxt;
    }
    idx = nxt, add += cadd;
  }
  cout << cnt;

  return 0;
}