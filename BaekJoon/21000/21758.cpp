// Title : 꿀 따기
// Link  : https://www.acmicpc.net/problem/21758 
// Time  : 8 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    arr[i] = arr[i - 1] + x;
  }

  int maxx = 0, x;
  x = arr[n] - arr[1];
  for (int i = 2; i < n; i++) {
    maxx = max<int>(maxx, x + (arr[n] - arr[i]) - (arr[i] - arr[i - 1]));
  }
  x = arr[n - 1] - arr[0];
  for (int i = 2; i < n; i++) {
    maxx = max<int>(maxx, x + arr[i - 1] - (arr[i] - arr[i - 1]));
  }
  x = arr[n - 1] - arr[1];
  for (int i = 2; i < n; i++) {
    maxx = max<int>(maxx, x + arr[i] - arr[i - 1]);
  }
  cout << maxx;

  return 0;
}
