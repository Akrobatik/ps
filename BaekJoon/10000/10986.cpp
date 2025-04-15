// Title : 나머지 합
// Link  : https://www.acmicpc.net/problem/10986 
// Time  : 120 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int cnts[1000] = {1};
  int64_t ans = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum += x;
    ans += cnts[sum % m]++;
  }
  cout << ans;

  return 0;
}
