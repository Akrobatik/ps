// Title : 주사위
// Link  : https://www.acmicpc.net/problem/1233
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;
  vector<int> arr(a + b + c + 1);
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= c; k++) {
        ++arr[i + j + k];
      }
    }
  }

  int ans, maxx = INT_MIN;
  for (int i = 3; i <= a + b + c; i++) {
    if (maxx < arr[i]) ans = i, maxx = arr[i];
  }
  cout << ans;

  return 0;
}
