// Title : 카드 게임
// Link  : https://www.acmicpc.net/problem/11062 
// Time  : 104 ms
// Memory: 6164 KB

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
    vector<int> arr(n);
    for (auto& e : arr) cin >> e;

    vector<int> fwd(n + 1);
    for (int i = 0; i < n; i++) {
      fwd[i + 1] = fwd[i] + arr[i];
    }

    vector<vector<int>> memo(n, vector<int>(n, -1));

    cout << [&](this auto&& self, int l, int r) -> int {
      if (l == r) return arr[l];

      auto& res = memo[l][r];
      if (res != -1) return res;

      int lr = fwd[r + 1] - fwd[l];
      int lv = self(l + 1, r);
      int rv = self(l, r - 1);
      return res = lr - min<int>(lv, rv);
    }(0, n - 1) << "\n";
  }

  return 0;
}