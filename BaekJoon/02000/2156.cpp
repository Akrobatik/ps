// Title : 포도주 시식
// Link  : https://www.acmicpc.net/problem/2156 
// Time  : 0 ms
// Memory: 2180 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1), fwd(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= min<int>(n, 2); i++) {
    fwd[i] = fwd[i - 1] + arr[i];
  }

  for (int i = 3; i <= n; i++) {
    fwd[i] = fwd[i - 1];
    int sum = 0;
    for (int j = 1; j <= 2; j++) {
      sum += arr[i - j + 1];
      fwd[i] = max<int>(fwd[i], fwd[i - j - 1] + sum);
    }
  }
  cout << fwd[n];

  return 0;
}
