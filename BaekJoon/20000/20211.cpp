// Title : 게임 개발자 영우
// Link  : https://www.acmicpc.net/problem/20211 
// Time  : 40 ms
// Memory: 2396 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  vector<int> fwd[2];
  for (auto& e : fwd) e.assign(n + 1, 0);

  for (int i = 0; i < n; i++) {
    if (s[i] == 'H') {
      fwd[0][i + 1] = fwd[0][i] + 3;
      fwd[1][i + 1] = fwd[1][i] + 3;
    } else {
      if (i & 1) {
        fwd[0][i + 1] = fwd[0][i] + 1;
        fwd[1][i + 1] = fwd[1][i] + 5;
      } else {
        fwd[0][i + 1] = fwd[0][i] + 5;
        fwd[1][i + 1] = fwd[1][i] + 1;
      }
    }
  }

  vector<pair<int, int>> arr;
  int limit = max<int>(fwd[0][n], fwd[1][n]);
  for (int i = 1; i <= limit; i++) {
    int idx = 0, key = 0, cnt = 0;
    while (idx < n) {
      int nxt = lower_bound(fwd[key].begin() + idx, fwd[key].end(), fwd[key][idx] + i) - fwd[key].begin();
      idx = nxt, key = nxt & 1, ++cnt;
    }
    if (idx == n) arr.push_back({i, cnt});
  }

  cout << arr.size() << "\n";
  for (auto [x, y] : arr) cout << x << " " << y << "\n";

  return 0;
}