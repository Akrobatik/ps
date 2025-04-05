// Title : 윤년
// Link  : https://www.acmicpc.net/problem/2753
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << (n % 400 == 0 || n % 4 == 0 && n % 100 != 0 ? 1 : 0);

  return 0;
}
