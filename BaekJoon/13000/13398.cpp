// Title : 연속합 2
// Link  : https://www.acmicpc.net/problem/13398 
// Time  : 12 ms
// Memory: 3196 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1), fwd(n + 2), bwd(n + 2);
  for (int i = 1; i <= n; i++) cin >> arr[i];

  int maxx = INT_MIN, cur = 0;
  for (int i = 1; i <= n; i++) {
    cur = fwd[i] = max<int>(cur, 0) + arr[i];
    maxx = max<int>(maxx, cur);
  }
  cur = 0;
  for (int i = n; i >= 1; i--) {
    cur = bwd[i] = max<int>(cur, 0) + arr[i];
  }

  for (int i = 2; i <= n - 1; i++) {
    maxx = max<int>(maxx, fwd[i - 1] + bwd[i + 1]);
  }
  cout << maxx;

  return 0;
}
