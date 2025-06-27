// Title : 대표 선수
// Link  : https://www.acmicpc.net/problem/2461 
// Time  : 200 ms
// Memory: 9236 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int nm = n * m;
  vector<pair<int, int>> arr(nm);
  for (int i = 0; i < n; i++) {
    int k = i * m;
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      arr[k + j] = {x, i};
    }
  }
  sort(arr.begin(), arr.end());

  int cnt[1000] = {};
  int all = 0;

  auto Inc = [&](int i) {
    auto [x, c] = arr[i];
    if (cnt[c]++ == 0) ++all;
  };

  auto Dec = [&](int i) {
    auto [x, c] = arr[i];
    if (--cnt[c] == 0) --all;
  };

  int l = 0, r = 0;
  int minn = INT_MAX;
  while (l < nm) {
    while (r < nm && all != n) Inc(r++);
    while (l < r && cnt[arr[l].second] > 1) Dec(l++);
    if (all != n) break;
    minn = min<int>(minn, arr[r - 1].first - arr[l].first);
    Dec(l++);
  }
  cout << minn;

  return 0;
}
