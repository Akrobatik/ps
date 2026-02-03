// Title : Adjusting Drones
// Link  : https://www.acmicpc.net/problem/35227 
// Time  : 12 ms
// Memory: 3584 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> cnt;

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    int m = n << 1;
    cnt.assign(m + 1, 0);

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ++cnt[x];
    }

    for (int i = 0; i < m; i++) {
      cnt[i + 1] += cnt[i];
    }

    auto Check = [&](int l, int r) {
      int lv = (l <= m ? cnt[l] : n);
      int rv = (r <= m ? cnt[r] : n);
      int len = r - l;
      return (rv - lv) < k + len;
    };

    int idx = 1, maxx = 0;
    while (idx <= m) {
      int nxt = idx;
      while (!Check(idx - 1, nxt)) ++nxt;
      maxx = max<int>(maxx, nxt - idx);
      idx = nxt + 1;
    }
    cout << maxx << "\n";
  }

  return 0;
}