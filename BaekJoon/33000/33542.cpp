// Title : 극적인 승리
// Link  : https://www.acmicpc.net/problem/33542 
// Time  : 228 ms
// Memory: 10948 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, n;
  cin >> a >> b >> n;

  vector<pair<int, int>> lr(n + 1);
  for (int i = 1; i <= n; i++) {
    auto& [l, r] = lr[i];
    cin >> l >> r;
  }

  vector<int> ls(n + 1), rs(n + 1);
  iota(ls.begin(), ls.end(), 0);
  iota(rs.begin(), rs.end(), 0);
  stable_sort(ls.begin(), ls.end(), [&](int lhs, int rhs) {
    return lr[lhs].first < lr[rhs].first;
  });
  stable_sort(rs.begin(), rs.end(), [&](int lhs, int rhs) {
    return lr[lhs].second < lr[rhs].second;
  });

  ++n;
  int bm = INT_MAX, bl, br;
  int l = 0, r = n, rem = a - b;
  while (l < n) {
    while (r > 0 && lr[ls[l]].first + lr[rs[r - 1]].second > rem) --r;
    if (l != 0 && r != n && ls[l] == rs[r]) ++r;
    if (r != n) {
      int cur = lr[ls[l]].first + lr[rs[r]].second;
      if (bm > cur) bm = cur, bl = ls[l], br = rs[r];
    }
    ++l;
  }

  if (bm == INT_MAX) {
    cout << "No";
  } else {
    if (bl == 0) bl = -1;
    if (br == 0) br = -1;
    cout << bl << " " << br;
  }

  return 0;
}