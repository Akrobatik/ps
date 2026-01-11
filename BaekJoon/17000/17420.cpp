// Title : 깊콘이 넘쳐흘러
// Link  : https://www.acmicpc.net/problem/17420 
// Time  : 32 ms
// Memory: 3944 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int64_t> arr(n), brr(n);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;

  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(), [&](int lhs, int rhs) {
    return brr[lhs] < brr[rhs];
  });

  int64_t ans = 0;
  int idx = 0;
  int64_t bnd = 0;
  while (idx < n) {
    int nxt = idx;
    int64_t val = brr[ids[idx]];
    while (nxt < n && val == brr[ids[nxt]]) ++nxt;

    int64_t maxx = 0;
    bnd = max<int64_t>(bnd, val);
    for (int i = idx; i < nxt; i++) {
      int64_t x = arr[ids[i]];
      if (x < bnd) {
        int64_t dt = bnd - x;
        int64_t cnt = (dt + 29) / 30;
        ans += cnt;
        x += cnt * 30;
      }
      maxx = max<int64_t>(maxx, x);
    }

    bnd = max<int64_t>(bnd, maxx);
    idx = nxt;
  }
  cout << ans;

  return 0;
}