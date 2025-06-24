// Title : 커피숍2
// Link  : https://www.acmicpc.net/problem/1275 
// Time  : 72 ms
// Memory: 3588 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int64_t> arr(n + 1), fwt(n + 1);

  auto Update = [&](int i, int64_t v) {
    int64_t d = v - arr[i];
    arr[i] += d;
    for (; i <= n; i += i & (-i)) fwt[i] += d;
  };

  auto Query = [&](int i) {
    int64_t res = 0;
    for (; i > 0; i -= i & (-i)) res += fwt[i];
    return res;
  };

  for (int i = 1; i <= n; i++) {
    int64_t x;
    cin >> x;
    Update(i, x);
  }

  while (q--) {
    int64_t x, y, a, b;
    cin >> x >> y >> a >> b;
    if (x > y) swap(x, y);
    cout << Query(y) - Query(x - 1) << "\n";
    Update(a, b);
  }

  return 0;
}
