// Title : 팩토리얼 2
// Link  : https://www.acmicpc.net/problem/27433 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t x = 1;
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) x *= i;
  cout << x;

  return 0;
}
