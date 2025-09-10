// Title : The Game of Death
// Link  : https://www.acmicpc.net/problem/11558 
// Time  : 4 ms
// Memory: 2152 KB

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
    vector<int> arr(n + 1);
    vector<bool> used(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int ans = 0, idx = 0;
    int cur = 1;
    while (!used[cur] && cur != n) {
      ++idx;
      used[cur] = true;
      cur = arr[cur];
      if (cur == n) ans = idx;
    }
    cout << ans << "\n";
  }

  return 0;
}
