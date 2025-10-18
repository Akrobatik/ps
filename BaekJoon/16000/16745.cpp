// Title : What Goes Up Must Come Down
// Link  : https://www.acmicpc.net/problem/16745 
// Time  : 20 ms
// Memory: 4356 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 1);
  stable_sort(ids.begin(), ids.end(), [&](int lhs, int rhs) {
    return arr[lhs] < arr[rhs];
  });

  vector<int> fwt(n + 1);

  auto Update = [&](int i) {
    for (; i <= n; i += i & (-i)) ++fwt[i];
  };

  auto Query = [&](int i) {
    int res = 0;
    for (; i > 0; i -= i & (-i)) res += fwt[i];
    return res;
  };

  int64_t ans = 0;
  int all = 0, idx = 0;
  vector<int> axr;
  while (idx < n) {
    axr.clear();
    int val = arr[ids[idx]];
    while (idx < n && arr[ids[idx]] == val) axr.push_back(ids[idx++]);

    int l = 0, r = axr.size() - 1;
    while (l <= r) {
      int fwd = axr[l], bwd = axr[r];
      int fcnt = (fwd - 1) - Query(fwd), bcnt = (n - bwd) - (all - Query(bwd));
      if (fcnt < bcnt) {
        ans += fcnt, ++l, ++all;
        Update(fwd);
      } else {
        ans += bcnt, --r, ++all;
        Update(bwd);
      }
    }
  }
  cout << ans;

  return 0;
}