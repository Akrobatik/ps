// Title : 배열 나누기
// Link  : https://www.acmicpc.net/problem/34049 
// Time  : 20 ms
// Memory: 5148 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int64_t> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    arr[i] = arr[i - 1] + x;
    if (arr[i] < 0) {
      cout << "-1";
      return 0;
    }
  }

  vector<int64_t> bwd(n + 2, INT64_MAX);
  for (int i = n; i >= 1; i--) {
    bwd[i] = min<int64_t>(arr[i], bwd[i + 1]);
  }

  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] <= bwd[i + 1]) ++ans;
  }
  cout << ans;

  return 0;
}