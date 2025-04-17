// Title : Scores of Final Examination
// Link  : https://www.acmicpc.net/problem/17577 
// Time  : 8 ms
// Memory: 2272 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  while (cin >> n >> m && n && m) {
    vector<vector<int>> arr(m, vector<int>(n));
    for (auto& vec : arr) {
      for (auto& e : vec) cin >> e;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; j < m; j++) {
        sum += arr[j][i];
      }
      ans = max<int>(ans, sum);
    }
    cout << ans << "\n";
  }

  return 0;
}
