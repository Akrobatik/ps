// Title : 트리
// Link  : https://www.acmicpc.net/problem/4256 
// Time  : 16 ms
// Memory: 2088 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> arr(n + 1), bxr(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      bxr[x] = i;
    }

    [&](this auto&& self, int pl, int pr, int il, int ir) {
      if (pl > pr || il > ir) return;
      int cur = arr[pl];
      int kth = bxr[cur];
      int sz = kth - il;

      self(pl + 1, pl + sz, il, kth - 1);
      self(pl + sz + 1, pr, kth + 1, ir);
      cout << cur << " ";
    }(1, n, 1, n);
    cout << "\n";
  }

  return 0;
}