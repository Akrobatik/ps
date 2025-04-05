// Title : 안정적인 구간
// Link  : https://www.acmicpc.net/problem/33704
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a, b;
  cin >> n >> a >> b;

  cout << (n == 2 && a > b ? "NO" : "YES");

  return 0;
}
