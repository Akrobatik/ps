// Title : Minimum Scalar Product (Small)
// Link  : https://www.acmicpc.net/problem/12723 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    vector<int> arr(n), brr(n);
    for (auto& e : arr) cin >> e;
    for (auto& e : brr) cin >> e;
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end(), greater<int>());

    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (int64_t)arr[i] * brr[i];
    }
    cout << "Case #" << tc << ": " << sum << "\n";
  }

  return 0;
}