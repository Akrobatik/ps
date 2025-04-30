// Title : 두 배
// Link  : https://www.acmicpc.net/problem/31963 
// Time  : 28 ms
// Memory: 3976 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int64_t> brr(60);
  for (int i = 0; i < brr.size(); i++) brr[i] = 1ll << i;

  int n;
  cin >> n;
  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;

  int sum = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i - 1] <= arr[i]) continue;
    int64_t x = arr[i - 1] / arr[i];
    auto it = lower_bound(brr.begin(), brr.end(), x);
    sum += it - brr.begin();
    arr[i] *= *it;
    if (arr[i - 1] > arr[i]) arr[i] <<= 1, ++sum;
  }
  cout << sum;

  return 0;
}
