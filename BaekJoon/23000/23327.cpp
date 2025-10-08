// Title : 리그전 오브 레전드
// Link  : https://www.acmicpc.net/problem/23327 
// Time  : 76 ms
// Memory: 3588 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int64_t> arr(n + 1), axr(n + 1);
  for (int i = 1; i <= n; i++) {
    int64_t x;
    cin >> x;
    arr[i] = arr[i - 1] + x;
    axr[i] = axr[i - 1] + x * x;
  }

  while (q--) {
    int l, r;
    cin >> l >> r;

    int64_t x = arr[r] - arr[l - 1];
    int64_t y = axr[r] - axr[l - 1];

    cout << ((x * x - y) >> 1) << "\n";
  }

  return 0;
}