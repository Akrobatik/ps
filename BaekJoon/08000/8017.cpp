// Title : Parcel
// Link  : https://www.acmicpc.net/problem/8017 
// Time  : 260 ms
// Memory: 17768 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> mat(n, vector<int>(n));
  vector<pair<int, int>> stk;

  for (auto& vec : mat) {
    for (auto& e : vec) cin >> e;
  }

  for (int j = 0; j < n; j++) {
    int cur = 0;
    for (int i = 0; i < n; i++) {
      cur = (!mat[i][j] ? cur + 1 : 0);
      mat[i][j] = cur;
    }
  }

  int maxx = 0;
  for (int h = 0; h < n; h++) {
    for (int i = 0; i < n; i++) {
      int x = mat[h][i];
      while (!stk.empty() && stk.back().first > x) {
        auto [y, idx] = stk.back();
        stk.pop_back();

        int w = i - (!stk.empty() ? stk.back().second + 1 : 0);
        int cur = y * w;
        maxx = max<int>(maxx, cur);
      }
      stk.push_back({x, i});
    }

    while (!stk.empty()) {
      auto [y, idx] = stk.back();
      stk.pop_back();

      int w = n - (!stk.empty() ? stk.back().second + 1 : 0);
      int cur = y * w;
      maxx = max<int>(maxx, cur);
    }
  }
  cout << maxx << "\n";

  return 0;
}