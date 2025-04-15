// Title : 좋다
// Link  : https://www.acmicpc.net/problem/1253 
// Time  : 172 ms
// Memory: 2160 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      int l = min<int>(i, j);
      int r = i ^ j ^ l;
      if (binary_search(arr.begin(), arr.begin() + l, arr[i] - arr[j])) {
        ++cnt;
        break;
      }
      if (binary_search(arr.begin() + l + 1, arr.begin() + r, arr[i] - arr[j])) {
        ++cnt;
        break;
      }
      if (binary_search(arr.begin() + r + 1, arr.end(), arr[i] - arr[j])) {
        ++cnt;
        break;
      }
    }
  }
  cout << cnt;

  return 0;
}
