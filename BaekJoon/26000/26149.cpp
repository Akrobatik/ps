// Title : 선물의 재분배
// Link  : https://www.acmicpc.net/problem/26149 
// Time  : 116 ms
// Memory: 11164 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> arr(n + 1), brr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++) cin >> brr[i];

  int maxx = 0, mi;
  for (int i = 1; i <= n; i++) {
    if (maxx < brr[i]) maxx = brr[i], mi = i;
  }

  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 1);
  stable_sort(ids.begin(), ids.end(), [&](int lhs, int rhs) {
    return arr[lhs] > arr[rhs];
  });

  vector<pair<int, int>> ans;
  for (auto i : ids) {
    if (i == mi) continue;
    if (arr[i] == 0) break;
    ans.push_back({mi, arr[i]});
  }

  for (int i = 1; i <= n; i++) {
    if (i == mi || brr[i] == 0) continue;
    ans.push_back({i, brr[i]});
  }

  cout << ans.size() << "\n";
  for (auto [a, b] : ans) {
    cout << "+ " << a << " " << b << "\n";
  }

  return 0;
}