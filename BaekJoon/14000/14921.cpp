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

  int minn = INT_MAX;
  for (int i = 0; i < n - 1; i++) {
    auto it = lower_bound(arr.begin() + i + 1, arr.end(), -arr[i]);
    if (it != arr.end() && abs(minn) > abs(arr[i] + *it)) minn = arr[i] + *it;
    if (--it != arr.begin() + i && abs(minn) > abs(arr[i] + *it)) minn = arr[i] + *it;
  }
  cout << minn;

  return 0;
}
