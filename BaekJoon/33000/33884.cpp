// Title : 클리크 조절
// Link  : https://www.acmicpc.net/problem/33884 
// Time  : 136 ms
// Memory: 5152 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> arr(n), brr(n);
  for (auto& [y, x] : arr) cin >> y >> x;
  for (auto& [y, x] : brr) cin >> y >> x;
  sort(arr.begin(), arr.end());
  sort(brr.begin(), brr.end());

  auto a = arr[0], b = brr[0];
  cout << b.first - a.first << " " << b.second - a.second;

  return 0;
}
