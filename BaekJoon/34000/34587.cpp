// Title : Palindromic Distance
// Link  : https://www.acmicpc.net/problem/34587 
// Time  : 96 ms
// Memory: 37588 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    int n = s.size();

    vector<vector<int>> memo(n, vector<int>(n, -1));

    cout << [&](this auto&& self, int l, int r) -> int {
      if (r <= l) return 0;

      auto& res = memo[l][r];
      if (res != -1) return res;
      res = INT_MAX;

      res = min<int>(res, self(l + 1, r - 1) + (s[l] != s[r]));
      res = min<int>(res, self(l + 1, r) + 1);
      res = min<int>(res, self(l, r - 1) + 1);
      return res;
    }(0, n - 1) << "\n";
  }

  return 0;
}