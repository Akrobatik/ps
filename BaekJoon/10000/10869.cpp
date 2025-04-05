// Title : 사칙연산
// Link  : https://www.acmicpc.net/problem/10869
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;

  cout << a + b << "\n"
       << a - b << "\n"
       << a * b << "\n"
       << a / b << "\n"
       << a % b;

  return 0;
}
