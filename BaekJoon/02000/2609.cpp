// Title : 최대공약수와 최소공배수
// Link  : https://www.acmicpc.net/problem/2609
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b;
  int mul = a * b;
  while ((c = a % b)) a = b, b = c;
  cout << b << "\n"
       << mul / b;

  return 0;
}
