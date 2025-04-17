// Title : 보물
// Link  : https://www.acmicpc.net/problem/1026 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n), brr(n);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;
  sort(arr.begin(), arr.end());
  sort(brr.begin(), brr.end(), greater<>());

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i] * brr[i];
  }
  cout << sum;

  return 0;
}
