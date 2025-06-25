// Title : 숫자고르기
// Link  : https://www.acmicpc.net/problem/2668 
// Time  : 0 ms
// Memory: 2024 KB

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1), memo(n + 1);
  vector<bool> used(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  int cnt = 1;
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (memo[i]) continue;

    int cur = i, start = cnt;
    while (memo[cur] == 0) {
      memo[cur] = cnt++;
      cur = arr[cur];
    }

    if (memo[cur] >= start) {
      do {
        ans.push_back(cur);
        used[cur] = true;
        cur = arr[cur];
      } while (!used[cur]);
    }
  }

  sort(ans.begin(), ans.end());

  cout << ans.size() << "\n";
  for (auto e : ans) cout << e << "\n";

  return 0;
}
