// Title : 수열 정렬
// Link  : https://www.acmicpc.net/problem/1015 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n), axr(n);
  for (auto& e : arr) cin >> e;
  iota(axr.begin(), axr.end(), 0);

  stable_sort(axr.begin(), axr.end(), [&](int lhs, int rhs) {
    return arr[lhs] < arr[rhs];
  });

  for (int i = 0; i < n; i++) {
    arr[axr[i]] = i;
  }

  for (auto e : arr) cout << e << " ";

  return 0;
}
