// Title : 물류 작업 최적화
// Link  : https://www.acmicpc.net/problem/33755 
// Time  : 52 ms
// Memory: 5536 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<int> fwd(n + 1), bwd(n + 1);
  for (int i = 1; i <= n; i++) {
    fwd[i] = max<int>(fwd[i - 1], 0) + arr[i];
    bwd[i] = max<int>(bwd[i - 1], 0) + arr[n - i + 1];
  }

  for (int i = 1; i <= n; i++) {
    cout << fwd[i] + bwd[n - i + 1] - arr[i] << " ";
  }

  return 0;
}
