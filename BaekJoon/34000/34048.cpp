// Title : 월향 조각사
// Link  : https://www.acmicpc.net/problem/34048 
// Time  : 28 ms
// Memory: 4372 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 2);
  for (int i = 1; i <= n; i++) cin >> arr[i];

  vector<int> fwd(n + 2), bwd(n + 2);
  for (int i = 1; i <= n; i++) {
    fwd[i] = min<int>(fwd[i - 1] + 1, arr[i]);
  }
  for (int i = n; i >= 1; i--) {
    bwd[i] = min<int>(bwd[i + 1] + 1, arr[i]);
  }

  int64_t ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += min<int>(fwd[i], bwd[i]);
  }
  cout << ans;

  return 0;
}