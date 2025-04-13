// Title : 소수 세기
// Link  : https://www.acmicpc.net/problem/29261 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int p;
  cin >> p;
  int x = (int)((double)(p * 2) / 3.0);
  if (!(x & 1)) --x;
  cout << x;

  return 0;
}
