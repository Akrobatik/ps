// Title : Coins
// Link  : https://www.acmicpc.net/problem/8298 
// Time  : 176 ms
// Memory: 18796 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  string s;
  cin >> n >> k >> s;

  int64_t sum = 0;
  vector<pair<int64_t, int>> arr(n + 1);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'O') {
      --sum;
    } else {
      sum += k;
    }
    arr[i] = {sum, i};
  }
  arr[n] = {0, -1};
  sort(arr.begin(), arr.end());

  int ans = 0;
  auto it = arr.begin();
  while (it != arr.end()) {
    auto [x, b] = *it++;
    auto nxt = upper_bound(it, arr.end(), x, [](int64_t lhs, const pair<int64_t, int>& rhs) {
      return lhs < rhs.first;
    });
    it = nxt--;
    ans = max<int>(ans, nxt->second - b);
  }
  cout << ans;

  return 0;
}
