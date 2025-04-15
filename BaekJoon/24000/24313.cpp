// Title : 알고리즘 수업 - 점근적 표기 1
// Link  : https://www.acmicpc.net/problem/24313 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a1, a0, c, n0;
  cin >> a1 >> a0 >> c >> n0;

  cout << (a0 + a1 * n0 <= c * n0 && a1 <= c);

  return 0;
}
