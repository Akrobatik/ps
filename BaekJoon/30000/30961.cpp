// Title : 최솟값, 최댓값
// Link  : https://www.acmicpc.net/problem/30961 
// Time  : 180 ms
// Memory: 5928 KB

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

  int64_t ans = 0;
  for (auto e : arr) {
    ans ^= (int64_t)e * e;
  }
  for (int i = 1; i < n; i++) {
    ans ^= (int64_t)arr[i - 1] * arr[i];
  }
  cout << ans;

  return 0;
}