// Title : 한 줄로 서기
// Link  : https://www.acmicpc.net/problem/1138 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int memo[10] = {};
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (memo[j]) continue;
      if (++cnt > x) {
        memo[j] = i;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << memo[i] << " ";
  }

  return 0;
}
