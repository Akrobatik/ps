// Title : 알고리즘 수업 - 피보나치 수 1
// Link  : https://www.acmicpc.net/problem/24416 
// Time  : 180 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int Fib1(int n) {
  if (n == 1 || n == 2) return 1;
  return Fib1(n - 1) + Fib1(n - 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << Fib1(n) << " " << max<int>(n - 2, 1);

  return 0;
}
