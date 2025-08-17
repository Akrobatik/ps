// Title : 의식의 광장
// Link  : https://www.acmicpc.net/problem/34139 
// Time  : 80 ms
// Memory: 4376 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(m);
  for (auto& e : arr) cin >> e >> e;

  vector<int> axr(m);
  iota(axr.begin(), axr.end(), 0);
  sort(axr.begin(), axr.end(), [&](int lhs, int rhs) {
    return arr[lhs] < arr[rhs];
  });

  vector<int> ans(m);
  for (int i = 0; i < m; i++) {
    ans[axr[i]] = i + 1;
  }

  cout << "YES\n";
  for (auto e : ans) cout << e << " ";

  return 0;
}
