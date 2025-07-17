// Title : 공통 순서쌍 찾기
// Link  : https://www.acmicpc.net/problem/34065 
// Time  : 72 ms
// Memory: 9140 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> arr(n + 1), brr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++) cin >> brr[i];

  vector<int> table(n + 1);
  for (int i = 1; i <= n; i++) table[arr[i]] = i;
  for (int i = 1; i <= n; i++) brr[i] = table[brr[i]];

  vector<pair<int, int>> lr(n + 2);
  for (int i = 1; i <= n; i++) {
    lr[i] = {i - 1, i + 1};
  }
  lr[0] = {0, 1};
  lr[n + 1] = {n, 0};

  vector<pair<int, int>> ans;
  for (int i = 1; ans.size() < k && i <= n; i++) {
    int x = brr[i];
    auto [l, r] = lr[x];
    lr[l].second = r;
    lr[r].first = l;
    while (ans.size() < k && r <= n) {
      ans.push_back({x, r});
      r = lr[r].second;
    }
  }

  if (ans.size() < k) {
    cout << "No";
  } else {
    cout << "Yes\n";
    for (auto [x, y] : ans) {
      cout << arr[x] << " " << arr[y] << "\n";
    }
  }

  return 0;
}
