// Title : 박스
// Link  : https://www.acmicpc.net/problem/9455 
// Time  : 20 ms
// Memory: 2152 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> memo(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        if (x) memo[j].push_back(n - i - 1);
      }
    }

    int64_t sum = 0;
    for (int i = 0; i < m; i++) {
      auto& vec = memo[i];
      int sz = vec.size();
      for (int j = 0; j < sz; j++) {
        sum += vec[j] - j;
      }
    }
    cout << sum << "\n";
  }

  return 0;
}
