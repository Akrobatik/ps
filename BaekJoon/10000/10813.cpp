// Title : 공 바꾸기
// Link  : https://www.acmicpc.net/problem/10813 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int memo[101] = {};
  iota(memo, memo + 101, 0);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    swap(memo[a], memo[b]);
  }

  for (int i = 1; i <= n; i++) cout << memo[i] << " ";

  return 0;
}
