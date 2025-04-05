// Title : 타일 밟기
// Link  : https://www.acmicpc.net/problem/6988
// Time  : 32 ms
// Memory: 3128 KB

#include <bits/stdc++.h>

using namespace std;

bool memo[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e, memo[e] = true;

  int64_t ans = 0;
  for (int i = 1; i < n; i++) {
    int r = arr[i];
    for (int j = 0; j < i; j++) {
      int d = r - arr[j];
      int cnt = 2, nxt = r + d;
      while (nxt <= 1000000 && memo[nxt]) nxt += d, ++cnt;
      if (cnt >= 3) {
        int64_t x = arr[j] + nxt - d;
        ans = max<int64_t>(ans, x * cnt / 2);
      }
    }
  }
  cout << ans;

  return 0;
}
