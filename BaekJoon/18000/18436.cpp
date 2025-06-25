// Title : 수열과 쿼리 37
// Link  : https://www.acmicpc.net/problem/18436 
// Time  : 44 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1), fwt(n + 1);

  auto Update = [&](int i, int x) {
    x &= 1;
    int d = x - arr[i];
    if (d == 0) return;
    arr[i] += d;
    for (; i <= n; i += i & (-i)) fwt[i] += d;
  };

  auto Query = [&](int i) {
    int res = 0;
    for (; i > 0; i -= i & (-i)) res += fwt[i];
    return res;
  };

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    Update(i, x);
  }

  int m;
  cin >> m;
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int i, x;
      cin >> i >> x;
      Update(i, x);
    } else {
      int l, r;
      cin >> l >> r;
      int ans = Query(r) - Query(l - 1);
      if (cmd == 2) ans = (r - l + 1) - ans;
      cout << ans << "\n";
    }
  }

  return 0;
}
