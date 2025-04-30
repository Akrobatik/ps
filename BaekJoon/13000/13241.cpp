// Title : 최소공배수
// Link  : https://www.acmicpc.net/problem/13241 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  cin >> a >> b;
  cout << (int64_t)a * b / GCD(a, b);

  return 0;
}
