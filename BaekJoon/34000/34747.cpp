// Title : Maximal Color Rectangle
// Link  : https://www.acmicpc.net/problem/34747 
// Time  : 448 ms
// Memory: 17900 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> mat(n, vector<int>(n));
  for (auto& vec : mat) {
    for (auto& e : vec) cin >> e;
  }

  int maxx = 0;
  vector<pair<int, int>> memo(n, {INT_MAX, 0});
  vector<pair<int, int>> stk;

  auto Calc = [&](int st, int en) {
    for (int i = st; i < en; i++) {
      int cur = memo[i].second;
      while (!stk.empty() && stk.back().first > cur) {
        auto [h, idx] = stk.back();
        stk.pop_back();

        int val;
        if (stk.empty()) {
          val = h * (i - st);
        } else {
          val = h * (i - stk.back().second - 1);
        }
        maxx = max<int>(maxx, val);
      }
      stk.push_back({cur, i});
    }

    while (!stk.empty()) {
      auto [h, idx] = stk.back();
      stk.pop_back();

      int val;
      if (stk.empty()) {
        val = h * (en - st);
      } else {
        val = h * (en - stk.back().second - 1);
      }
      maxx = max<int>(maxx, val);
    }
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cv = mat[i][j];
      auto [pv, ph] = memo[j];
      memo[j] = {cv, (cv == pv ? ph + 1 : 1)};
    }

    int idx = 0;
    while (idx < n) {
      int nxt = idx, val = mat[i][idx];
      while (nxt < n && val == mat[i][nxt]) ++nxt;
      Calc(idx, nxt);
      idx = nxt;
    }
  }
  cout << maxx;

  return 0;
}