// Title : e-코너 시스템 테스트 (Easy)
// Link  : https://www.acmicpc.net/problem/34010 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int d = (n - 1) << 1;
  cout << d << " " << d - 1;

  return 0;
}
