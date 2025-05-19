// Title : 빗질의 중요성
// Link  : https://www.acmicpc.net/problem/33870 
// Time  : 0 ms
// Memory: 2180 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n + 1), brr(m + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= m; i++) cin >> brr[i];

  auto crr = arr;
  for (int i = 1; i <= m; i++) {
    int x = brr[i];
    if (crr[x] >= i || brr[i - 1] == x) crr[x] = arr[x] + i;
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (crr[i] <= m) ++cnt;
  }
  cout << cnt;

  return 0;
}
