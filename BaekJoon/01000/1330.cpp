// Title : 두 수 비교하기
// Link  : https://www.acmicpc.net/problem/1330
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;
  cout << (a > b ? ">" : a < b ? "<" : "==");

  return 0;
}
