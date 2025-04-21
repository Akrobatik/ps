// Title : 공 넣기
// Link  : https://www.acmicpc.net/problem/10810 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int memo[100] = {};
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = a - 1; i < b; i++) {
      memo[i] = c;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << memo[i] << " ";
  }

  return 0;
}
