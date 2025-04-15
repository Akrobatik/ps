// Title : 나머지
// Link  : https://www.acmicpc.net/problem/10430 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;
  cout << (a + b) % c << "\n"
       << (a % c + b % c) % c << "\n"
       << a * b % c << "\n"
       << (a % c) * (b % c) % c;

  return 0;
}
