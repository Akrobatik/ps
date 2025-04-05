// Title : 막대과자 포장
// Link  : https://www.acmicpc.net/problem/14219
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;
  cout << (a * b % 3 == 0 ? "YES" : "NO");
  return 0;
}
