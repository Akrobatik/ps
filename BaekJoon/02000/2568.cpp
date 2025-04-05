// Title : 전깃줄 － 2
// Link  : https://www.acmicpc.net/problem/2568
// Time  : 36 ms
// Memory: 3584 KB

#include <bits/stdc++.h>

using namespace std;

pair<int, int> lines[100000];
int memo[100000];
int ans[100000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> lines[i].first >> lines[i].second;
  sort(lines, lines + n);

  auto me = memo;
  auto ae = ans;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int v = lines[i].second;
    auto it = lower_bound(memo, me, v);
    if (it != me) {
      *it = v;
      *ae++ = it - memo;
    } else {
      *ae++ = me - memo;
      *me++ = v;
    }
  }

  int nm = me - memo;
  me = memo;
  cout << n - nm-- << "\n";
  for (int i = n - 1; i >= 0; i--) {
    if (ans[i] == nm) {
      --nm;
    } else {
      *me++ = lines[i].first;
    }
  }

  for (auto p = me - 1; p >= memo; --p) cout << *p << "\n";

  return 0;
}
