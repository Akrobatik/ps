// Title : 곱셈
// Link  : https://www.acmicpc.net/problem/2588 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;
  cout << a * (b % 10) << "\n"
       << a * (b / 10 % 10) << "\n"
       << a * (b / 100) << "\n"
       << a * b;

  return 0;
}
