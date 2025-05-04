// Title : 주몽
// Link  : https://www.acmicpc.net/problem/1940 
// Time  : 0 ms
// Memory: 2200 KB

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

  int l = 0, r = n - 1, cnt = 0;
  while (l < r) {
    int sum = arr[l] + arr[r];
    if (sum == m) {
      ++cnt, ++l, --r;
    } else if (sum > m) {
      --r;
    } else {
      ++l;
    }
  }
  cout << cnt;

  return 0;
}