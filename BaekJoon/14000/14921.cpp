// Title : 용액 합성하기
// Link  : https://www.acmicpc.net/problem/14921 
// Time  : 12 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int minn = INT_MAX, ans;

  auto Update = [&](int l, int r) {
    int cur = arr[l] + arr[r];
    int abv = abs(cur);
    if (minn > abv) minn = abv, ans = cur;
  };

  int l = 0, r = n - 1;
  while (l < r) {
    while (l < r - 1 && arr[l] + arr[r] >= 0) --r;
    if (r + 1 != n) Update(l, r + 1);
    Update(l++, r);
  }
  cout << ans;

  return 0;
}
