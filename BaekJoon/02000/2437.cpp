// Title : 저울
// Link  : https://www.acmicpc.net/problem/2437 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());
  
  int idx = 0, ans = 1;
  while (idx < n && arr[idx] <= ans) ans += arr[idx++];
  cout << ans;

  return 0;
}
