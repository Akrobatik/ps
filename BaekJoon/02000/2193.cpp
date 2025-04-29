// Title : 이친수
// Link  : https://www.acmicpc.net/problem/2193 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int64_t memo[91] = {0, 1, 1};
  for (int i = 3; i <= n; i++) memo[i] = memo[i - 1] + memo[i - 2];
  cout << memo[n];

  return 0;
}
