// Title : 수열
// Link  : https://www.acmicpc.net/problem/2559 
// Time  : 8 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> arr(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[i + 1] = arr[i] + x;
  }

  int maxx = INT_MIN;
  for (int i = k; i <= n; i++) {
    maxx = max<int>(maxx, arr[i] - arr[i - k]);
  }
  cout << maxx;

  return 0;
}
