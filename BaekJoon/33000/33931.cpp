// Title : 체크박스 누르기
// Link  : https://www.acmicpc.net/problem/33931 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int q = m / n, r = m % n;
  cout << ((q & 1) ? n - r : r);

  return 0;
}
