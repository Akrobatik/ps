// Title : 수 고르기
// Link  : https://www.acmicpc.net/problem/2230 
// Time  : 16 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  int minn = INT_MAX, l = 0, r = 0;
  while (l < n) {
    while (r < n && arr[r] - arr[l] < m) ++r;
    if (r == n) break;
    minn = min<int>(minn, arr[r] - arr[l++]);
  }
  cout << minn;

  return 0;
}
