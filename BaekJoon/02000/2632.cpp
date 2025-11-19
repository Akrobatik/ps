// Title : 피자판매
// Link  : https://www.acmicpc.net/problem/2632 
// Time  : 376 ms
// Memory: 54172 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t x, n, m;
  cin >> x >> n >> m;

  vector<int64_t> arr(n << 1 | 1);
  for (int i = 1; i <= n; i++) {
    int64_t v;
    cin >> v;
    arr[i] = arr[i + n] = v;
  }
  for (int i = 1; i <= (n << 1); i++) {
    arr[i] += arr[i - 1];
  }

  vector<int64_t> brr(m << 1 | 1);
  for (int i = 1; i <= m; i++) {
    int64_t v;
    cin >> v;
    brr[i] = brr[i + m] = v;
  }
  for (int i = 1; i <= (m << 1); i++) {
    brr[i] += brr[i - 1];
  }

  map<int64_t, int64_t> ax, bx;
  ++ax[arr[n]], ++ax[0];
  ++bx[brr[m]], ++bx[0];
  for (int len = 1; len < n; len++) {
    for (int i = 0; i < n; i++) {
      ++ax[arr[i + len] - arr[i]];
    }
  }
  for (int len = 1; len < m; len++) {
    for (int i = 0; i < m; i++) {
      ++bx[brr[i + len] - brr[i]];
    }
  }

  int64_t ans = 0;
  for (auto [av, ac] : ax) {
    auto it = bx.find(x - av);
    if (it != bx.end()) {
      auto [bv, bc] = *it;
      ans += ac * bc;
    }
  }
  cout << ans;

  return 0;
}