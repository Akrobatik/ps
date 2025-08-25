// Title : 스위치
// Link  : https://www.acmicpc.net/problem/30460 
// Time  : 16 ms
// Memory: 3588 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 3);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    arr[i] = arr[i - 1] + x;
  }
  arr[n + 2] = arr[n + 1] = arr[n];

  vector<int> memo(n + 3);
  memo[1] = arr[1], memo[2] = arr[2];
  for (int i = 3; i <= n + 2; i++) {
    memo[i] = max<int>(memo[i - 1] + arr[i] - arr[i - 1], memo[i - 3] + ((arr[i] - arr[i - 3]) << 1));
  }
  cout << memo[n + 2];

  return 0;
}
