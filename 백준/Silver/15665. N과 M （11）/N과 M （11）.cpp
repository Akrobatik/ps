#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  vector<int> ans(m);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());

  function<void(int)> dfs = [&](int i) {
    if (i == m) {
      for (auto e : ans) cout << e << " ";
      cout << "\n";
      return;
    }
    for (auto e : arr) {
      ans[i] = e;
      dfs(i + 1);
    }
  };

  dfs(0);

  return 0;
}
