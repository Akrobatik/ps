// Title : Highway Track
// Link  : https://www.acmicpc.net/problem/14740 
// Time  : 96 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int m = n << 1;
  vector<int64_t> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    arr[i] -= x;
  }

  for (int i = 1; i <= n; i++) {
    arr[i] += arr[i - 1];
  }

  int cnt = 0;
  int64_t minn = INT64_MAX;
  for (int i = 1; i <= n; i++) {
    if (minn > arr[i]) {
      minn = arr[i], cnt = 1;
    } else if (minn == arr[i]) {
      ++cnt;
    }
  }
  cout << cnt;

  return 0;
}
