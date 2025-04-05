// Title : 알람 시계
// Link  : https://www.acmicpc.net/problem/2884
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, m;
  cin >> h >> m;
  m += (h * 60) + (24 * 60 - 45);
  h = (m / 60) % 24;
  m %= 60;
  cout << h << " " << m;

  return 0;
}
