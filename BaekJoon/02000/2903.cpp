// Title : 중앙 이동 알고리즘
// Link  : https://www.acmicpc.net/problem/2903 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x = 2;
  int n;
  cin >> n;
  while (n--) x = x * 2 - 1;
  cout << x * x;

  return 0;
}
