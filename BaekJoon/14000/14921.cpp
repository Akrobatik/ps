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
  int l = 0, r = n - 1;
  while (l < r) {
    while (l < r - 1 && arr[l] + arr[r - 1] >= 0) --r;
    int cur = abs(arr[l] + arr[r]);
    if (minn > cur) minn = cur, ans = arr[l] + arr[r];
    if (l != --r) {
      cur = abs(arr[l] + arr[r]);
      if (minn > cur) minn = cur, ans = arr[l] + arr[r];
    }
    ++l, ++r;
  }
  cout << ans;

  return 0;
}
