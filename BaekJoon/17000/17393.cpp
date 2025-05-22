// Title : 다이나믹 롤러
// Link  : https://www.acmicpc.net/problem/17393 
// Time  : 304 ms
// Memory: 9836 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int64_t> arr(n), brr(n);
  for (auto& e : arr) cin >> e;
  for (auto& e : views::reverse(brr)) cin >> e;

  for (int i = 0; i < n; i++) {
    brr.pop_back();
    auto it = lower_bound(brr.begin(), brr.end(), arr[i], greater<int64_t>());
    cout << brr.end() - it << " ";
  }

  return 0;
}
