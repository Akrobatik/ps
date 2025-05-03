// Title : 주유소
// Link  : https://www.acmicpc.net/problem/13305 
// Time  : 28 ms
// Memory: 3200 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> arr[i];
  }
  for (int i = n - 1; i; i--) {
    arr[i - 1] += arr[i];
  }
  vector<pair<int, int>> brr(n);
  for (int i = 0; i < n; i++) {
    cin >> brr[i].first;
    brr[i].second = i;
  }
  sort(brr.begin(), brr.end());

  int64_t sum = 0;
  int r = n - 1;
  for (auto [x, i] : brr) {
    if (i > r) continue;
    sum += (int64_t)x * (arr[i] - arr[r]);
    r = i;
  }
  cout << sum;

  return 0;
}
