// Title : За коллективизм!
// Link  : https://www.acmicpc.net/problem/28977 
// Time  : 40 ms
// Memory: 4488 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[i] = {x, i + 1};
  }
  sort(arr.begin(), arr.end());

  vector<int64_t> fwd(n + 1);
  for (int i = 0; i < n; i++) {
    fwd[i + 1] = fwd[i] + arr[i].first;
  }

  int maxx = -1, mi = 0;
  for (int i = 0; i < n; i++) {
    auto Check = [&](int64_t x) {
      return fwd[i + x] - fwd[i] - x * arr[i].first <= k;
    };

    int lo = -1, hi = n - i + 1;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      if (Check(mid)) {
        lo = mid;
      } else {
        hi = mid;
      }
    }

    if (maxx < lo) maxx = lo, mi = i;
  }

  vector<int> ans;
  for (int i = 0; i < mi; i++) ans.push_back(arr[i].second);
  for (int i = mi + maxx; i < n; i++) ans.push_back(arr[i].second);
  sort(ans.begin(), ans.end());

  cout << ans.size() << "\n";
  for (auto e : ans) cout << e << " ";

  return 0;
}
