// Title : 팩토리얼
// Link  : https://www.acmicpc.net/problem/10872 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int64_t x = 1;
  for (int i = 2; i <= n; i++) x *= i;
  cout << x;

  return 0;
}
